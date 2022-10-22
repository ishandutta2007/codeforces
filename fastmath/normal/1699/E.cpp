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
const int M = 5e6+7;
bool w[M];
int mnv[M];
signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    auto solve = [&] () {
        int n, m;
        cin >> n >> m;

        FORN (x, m) {
            w[x] = 0;
        }   

        vi a(n);
        cin >> a;

        int mn = M, mx = -1;
        each (e, a) {
            ckmin(mn, e);
            ckmax(mx, e);
        }

        int ans = mx - mn;

        each (e, a) w[e] = 1;

        int dif = 0;
        FORN (x, m) dif += w[x];
        FORN (x, m) mnv[x] = 0;
        int r = 1;
        int bad = dif;
        for (int l = 1; l * l <= m; ++l) {
            if (l > 1) {
                for (int i = l - 1; i <= m; i += l - 1) {
                    if (mnv[i] == l - 1) {
                        if (w[i]) bad++;
                    }
                }                
            }
            while (bad && r <= m) {
                if (mnv[r] < l && w[r]) {
                    bad--;
                }
                mnv[r] = r;
                for (int i = max(l, 2ll); i * r <= m; ++i) {
                    if (w[i * r]) {
                        bad -= mnv[i * r] < l;
                    }
                    ckmax(mnv[i * r], min(mnv[i], r));
                    if (w[i * r]) {
                        bad += mnv[i * r] < l;
                    }
                }
                r++;
            }
            if (bad) {
                break;
            }
            debug(mp(l, r));
            if (bad == 0) {
                ckmin(ans, r - l - 1);
            }
            if (w[l]) {
                break;
            }
        }
        cout << ans << endl;
    };  
    int t;
    cin >> t;
    rep (t) {
        solve();
    }
}