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
#include <array>
#include <functional>
#include <stack>
#include <memory>
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

#ifdef LOCAL
#define debug(x) std::cerr << #x << ": " << x << '\n';
#define debug2(x, y) std::cerr << #x << ", " << #y << ": " << x << ", " << y << '\n';
#define debug3(x, y, z) std::cerr << #x << ", " << #y << ", " << #z << ": " << x << ", " << y << ", " << z << '\n';
#else
#define debug(x)
#define debug2(x, y) 
#define debug3(x, y, z) 
#endif

#define FORI(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) FORI(i,0,a)
#define ROFI(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) ROFI(i,0,a)
#define rep(a) FOR(_,a)
#define each(a,x) for (auto& a: x)
#define FORN(i, n) FORI(i, 1, n + 1)

using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::pair <T, T> & data)
{
    input >> data.x >> data.y;
    return input;
}
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
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
std::ostream& operator <<(std::ostream& output, const __int128 &x)
{
    __int128 n = x;
    if (n == 0) {
        output << "0";
        return output;
    }
    if (n < 0) {
        n = -n;
        output << "-";
    }
    string s;
    while (n) {
        s += '0' + (n%10);
        n /= 10;
    }
    reverse(all(s));
    cout << s;
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
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
int Bit(int mask, int bit) { return (mask >> bit) & 1; }
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    auto solve = [&] () {
        int n, k;
        cin >> n >> k;

        vi in(n + 1);
        rep (k) {
            int u;
            cin >> u;
            in[u] = 1;
        }



        V <vi> g(n + 1);
        rep (n - 1) {
            int u, v;
            cin >> u >> v;
            g[u].app(v); g[v].app(u);
        }

        vi h(n + 1, n + 1), d(n + 1,n +1);
        function <void (int , int, int)>  dfs = [&] (int u, int p, int dep) {
            int s = 0, md = n + 1, lf = 1;

            each (v, g[u]) {
                if (v != p)  {
                    lf = 0;
                    dfs(v, u, dep + 1);
                    s += h[v];
                    ckmin(md, d[v] + 1);
                }
            }

            if (lf) {
            if (in[u]) {
                h[u] = 1;
                d[u] = 0;
            }
            else {
                h[u] = n + 1;

            }
            return;
            }

            if (s < n) {
                h[u] = s;
                d[u] = md;
            }

            each (v, g[u]) {
                if (v != p)  {
                    if (h[v] >= n && d[u] > dep) {
                        h[u] = n + 1;
                    }
                }
            }

            each (v, g[u]) {
                if (v != p)  {
                    if (d[v] + 1 <= dep && h[v] < n) {
                        if (mp(h[v], d[v] + 1) < mp(h[u], d[u])) {
                        h[u] = h[v];
                        d[u] = d[v] + 1;                            
                        }

                    }
                }
            }

            if (in[u]) {
                h[u] = 1;
                d[u] = 0;
            }
        };

        dfs(1, 1, 0);

        if (h[1] < n) cout << h[1] << endl;
        else cout << -1 << endl;
    };
    int t;
    cin >> t;
    rep (t) {
        solve();
    }
}