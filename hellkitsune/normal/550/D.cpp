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

int k;
int nx = 3;
queue<int> q;
vector<PII> ans;
vector<int> tmp;

void solve(int st) {
    q.push(st);
    int fr = 1;
    while (fr % k != 0) {
        int v = q.front();
        q.pop();
        REP(i, k - 1) {
            ans.pb(mp(v, nx));
            q.push(nx++);
        }
        fr += k - 2;
    }
    while (fr != 0) {
        REP(i, k) tmp.pb(q.front()), q.pop();
        REP(i, k) for (int j = i + 1; j < k; ++j) {
            ans.pb(mp(tmp[i], tmp[j]));
        }
        tmp.clear();
        fr -= k;
    }
    assert(q.empty());
}

int main() {
    scanf("%d", &k);
    if (k % 2 == 0) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    ans.pb(mp(1, 2));
    solve(1);
    solve(2);
    printf("%d %d\n", nx - 1, (int)ans.size());
    for (PII e : ans) printf("%d %d\n", e.first, e.second);
    return 0;
}