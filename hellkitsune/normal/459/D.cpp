#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <unordered_map>
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

int n, a[1000000];
int d[1000000], e[1000000];
unordered_map<int, int> ma;
int fen[1000001] = {};

inline void fen_inc(int v) {
    for (; v <= n; v |= v + 1)
        ++fen[v];
}

inline int fen_query(int v) {
    int ret = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1)
        ret += fen[v];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) d[i] = ++ma[a[i]];
    ma.clear();
    for (int i = n - 1; i >= 0; --i) e[i] = ++ma[a[i]];
    LL ans = 0;
    for (int i = n - 1; i > 0; --i) {
        fen_inc(e[i]);
        ans += fen_query(d[i - 1] - 1);
    }
    cout << ans << '\n';
    return 0;
}