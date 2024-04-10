#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cerr << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> void re(V<T>& x) { 
    trav(a, x)
        cin >> a;
}
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}
signed main() {
    #ifdef ONLINE_JUDGE
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    const int INF = 1e18;
    V <vi> a(4), dp(4);
    FOR (i, 4) {
        int sz;
        cin >> sz;
        a[i].resize(sz);
        dp[i].resize(sz, INF);
    }
    FOR (i, 4)
        re(a[i]);
    FOR (i, a[0].size())
        dp[0][i] = a[0][i];
    for (int i = 1; i <= 3; ++i) {

        V <ii> ord;
        FOR (j, a[i - 1].size())
            ord.app(mp(dp[i - 1][j], j));
        sort(all(ord));

        int m;
        cin >> m;
        V <set <int> > ban(a[i].size());
        while (m--) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            ban[v].insert(u);
        }

        FOR (j, a[i].size()) {
            int ptr = 0;
            while (ptr < ord.size() && ban[j].count(ord[ptr].y)) {
                ptr++;
            }
            if (ptr < ord.size())
                dp[i][j] = ord[ptr].x + a[i][j];
        }
    }

    int ans = INF;
    FOR (i, a[3].size())
        ckmin(ans, dp[3][i]);
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
}