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

int n, k;
int a[100], b[100];
set<int> se, se2;
map<int, int> ma;
int rev[200];
int mac = 0;
vector<int> fr[200];
set<int> ans[200];

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d%d", a + i, b + i);
    REP(i, n) se.insert(a[i]), se.insert(b[i]);
    for (int x : se) ma[x] = mac, rev[mac] = x, ++mac;
    REP(i, n) a[i] = ma[a[i]], b[i] = ma[b[i]];
    REP(i, n) fr[a[i]].pb(b[i]), fr[b[i]].pb(a[i]);
    REP(i, mac) {
        se.clear();
        for (int x : fr[i]) se.insert(x);
        se.insert(i);
        int cnt = (int)fr[i].size();
        REP(x, mac) if (!se.count(x)) {
            int cur = 0;
            for (int y : fr[x]) if (y != i && se.count(y))
                ++cur;
            if (cur * 100 >= k * cnt)
                ans[i].insert(x);
        }
    }
    REP(i, mac) {
        printf("%d: %d", rev[i], (int)ans[i].size());
        for (int x : ans[i])
            printf(" %d", rev[x]);
        printf("\n");
    }
    return 0;
}