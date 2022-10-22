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

const int N = 1e6+7;
int ri[2][N], le[2][N], ans[2][N];

// le ->
// ri <-

signed main() {
    #ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n; cin >> n;
    vi a(n + 1), b(n + 1), d(n + 1);
    FORN (i, n) cin >> a[i];
    FORN (i, n) cin >> b[i];
    b[1] = 0;
    FORN (i, n) d[i] = b[i] - a[i];

    const int M = 1e9+7, INF = 1e18+7;

    int mx = 0;

    vi cf(n + 1);
    cf[1] = 1;
    FORN (i, n) {
        for (int j = 2 * i; j <= n; j += i) {
            cf[j] -= cf[i];
            d[j] -= d[i];
        }
        //ans += abs(cf[i] * x + d[i])
        //cf[i] * x + d[i] <= 0
        //x <= -d[i] / cf[i]
        //x >= -d[i] / cf[i]

        ckmax(mx, abs(cf[i]));
        ckmax(mx, abs(d[i]));

        //debug(i);
        //debug(mp(cf[i], d[i]));

        if (cf[i] == 0) {
            le[0][1] += abs(d[i]);
        }
        else if (cf[i] > 0) {
            int up = div_down(-d[i], cf[i]);
            if (up >= 1) {
                //if x <= up : abs(cf[i] * x + d[i]) = -cf[i] * x - d[i]
                ri[0][min(up, N - 1)] -= d[i];
                ri[1][min(up, N - 1)] -= cf[i];
            }
            up++;
            if (up < N) {
                //if x >= up : abs(cf[i] * x + d[i]) = cf[i] * x + d[i]
                le[0][max(up, 1ll)] += d[i];
                le[1][max(up, 1ll)] += cf[i];
            }
        }
        else {
            int down = div_up(-d[i], cf[i]);
            if (down < N) {
                //if x >= down : 
                le[0][max(down, 1ll)] -= d[i];
                le[1][max(down, 1ll)] -= cf[i];
            }
            down--;
            if (down >= 1) {
                //if x <= down : 
                ri[0][min(down, N - 1)] += d[i];
                ri[1][min(down, N - 1)] += cf[i];
            }
        }
    }

    debug(mx);

    FOR (t, 2) {
        for (int i = 1; i < N; ++i) {
            le[t][i] += le[t][i - 1];
            ans[t][i] += le[t][i];
        }
        for (int i = N - 2; i >= 0; --i) {
            ri[t][i] += ri[t][i + 1];
            ans[t][i] += ri[t][i];
        }
    }

    int q;
    cin >> q;
    rep (q) {
        int x;
        cin >> x;
        cout << ans[0][x] + ans[1][x] * x << endl;
    }
}