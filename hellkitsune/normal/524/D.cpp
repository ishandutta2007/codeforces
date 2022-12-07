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
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, t;
char s[22];
int ans[20000];
int nx = 1;
int lt[20001];
bool inq[20001] = {};

struct Cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        if (lt[lhs] != lt[rhs]) return lt[lhs] < lt[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> q;

int getTime(char *s) {
    int t = ((s[0] - '0') * 10 + s[1] - '0') * 3600;
    t += ((s[3] - '0') * 10 + s[4] - '0') * 60;
    t += (s[6] - '0') * 10 + s[7] - '0';
    return t;
}

int main() {
    scanf("%d%d%d", &n, &m, &t);
    bool flag = false;
    REP(query, n) {
        scanf("%s", s);
        int x = getTime(s);
        while (!q.empty() && lt[*q.begin()] <= x)
            inq[*q.begin()] = false, q.erase(q.begin());
        if ((int)q.size() == m) {
            int theGuy = *q.rbegin();
            ans[query] = theGuy;
            q.erase(theGuy);
            lt[theGuy] = x + t;
            q.insert(theGuy);
        } else {
            ans[query] = nx;
            inq[nx] = true;
            lt[nx] = x + t;
            q.insert(nx);
            ++nx;
        }
        if ((int)q.size() == m)
            flag = true;
    }
    if (flag) {
        printf("%d\n", nx - 1);
        REP(i, n) printf("%d\n", ans[i]);
    } else {
        printf("No solution\n");
    }
    return 0;
}