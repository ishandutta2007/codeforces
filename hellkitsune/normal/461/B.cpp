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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1e9 + 7;

int n;
vector<int> g[100000];
int b[100000];
vector<PII> t[100000];

LL P(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

LL D(LL a, LL b) {
    return (a * P(b, MOD - 2)) % MOD;
}

PII dfs(int v) {
    if (b[v]) {
        LL ret = 1;
        for (int to : g[v]) {
            PII tmp = dfs(to);
            ret = (ret * (tmp.first + tmp.second)) % MOD;
        }
        return mp(0, (int)ret);
    } else {
        LL ret = 1, ret2 = 0;
        for (int to : g[v]) {
            PII tmp = dfs(to);
            t[v].pb(tmp);
            ret = (ret * (tmp.first + tmp.second)) % MOD;
        }
        for (PII z : t[v])
            ret2 = (ret2 + D(ret, z.first + z.second) * z.second) % MOD;
        return mp((int)ret, (int)ret2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        g[x].pb(i);
    }
    REP(i, n) cin >> b[i];
    cout << dfs(0).second << '\n';
    return 0;
}