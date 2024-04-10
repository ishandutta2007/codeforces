#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int l[100], r[100], ord[100];
int ans[100];

bool cmp(const int &lhs, const int &rhs) {
    return l[lhs] < l[rhs];
}

struct Cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        return r[lhs] > r[rhs];
    }
};

priority_queue<int, vector<int>, Cmp> q;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", l + i, r + i);
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    for (int beg = 0; beg < n; ) {
        int end = beg + 1;
        while (end < n && l[ord[beg]] == l[ord[end]]) ++end;
        int curT = l[ord[beg]];
        for (int i = beg; i < end; ++i) {
            q.push(ord[i]);
        }
        while (!q.empty()) {
            int v = q.top();
            q.pop();
            ans[v] = curT++;
            while (end < n && l[ord[end]] == curT) {
                q.push(ord[end]);
                ++end;
            }
        }
        beg = end;
    }
    REP(i, n) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}