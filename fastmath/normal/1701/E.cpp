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
#else
#define debug(x)
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

const int INF = 1e9+7;

const int N = 5003;
int dpl[N][N], dpr[N][N];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    auto solve = [&] () {
        int m, n;
        cin >> m >> n;

        string s, t;
        cin >> s >> t;

        FOR (i, m + 1) {
            FOR (j, m + 1) {
                dpl[i][j] = dpr[i][j] = INF;
            }
        }

        dpl[0][0] = 0;
        FOR (i, m) {
            FOR (j, n + 1) {
                if (dpl[i][j] != INF) {
                    if (j < n && s[i] == t[j]) {
                        ckmin(dpl[i + 1][j + 1], dpl[i][j]);
                    }
                    ckmin(dpl[i + 1][j], i + 1);
                }
            }
        }

        dpr[m][0] = 0;
        ROF (i, m) {
            FOR (j, n + 1) {
                if (dpr[i + 1][j] != INF) {
                    if (j < n && s[i] == t[n - 1 - j]) {
                        ckmin(dpr[i][j + 1], dpr[i + 1][j]);
                    }
                    ckmin(dpr[i][j], m - i);
                }
            }
        }

        if (dpr[0][n] == INF) {
            cout << -1 << endl;
            return;
        }

        int ans = dpr[0][n] - (m - n);

        FOR (i, m + 1) {
            FOR (b, n + 1) {
                int r = dpr[i][b];
                int l = dpl[i][n - b];
                ckmin(ans, b + l + 1);
            }
        }

        ans += m - n;
        cout << ans << endl;
    };
    int t;
    cin >> t;
    rep (t) {
        solve();
    }
}