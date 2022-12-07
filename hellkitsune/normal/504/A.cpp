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

vector<PII> ans;
int n;
int deg[1 << 16], s[1 << 16];
queue<int> q;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", deg + i, s + i);
    REP(i, n) if (deg[i] == 1) {
        q.push(i);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (deg[v] == 0) continue;
        ans.pb(mp(v, s[v]));
        s[s[v]] ^= v;
        if (--deg[s[v]] == 1) {
            q.push(s[v]);
        }
        deg[v] = 0;
        s[v] = 0;
    }
    printf("%d\n", (int)ans.size());
    for (PII x : ans) printf("%d %d\n", x.first, x.second);
    return 0;
}