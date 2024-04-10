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

template<int MOD, int RT> struct mint {
    static const __int128 mod = MOD;
    static constexpr mint rt() { return RT; } // primitive root for FFT
    __int128 v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
    mint() { v = 0; }
    mint(__int128 _v) { v = (__int128)((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD; }
    friend bool operator==(const mint& a, const mint& b) { 
        return a.v == b.v; }
    friend bool operator!=(const mint& a, const mint& b) { 
        return !(a == b); }
    friend bool operator<(const mint& a, const mint& b) { 
        return a.v < b.v; }
 
    mint& operator+=(const mint& m) { 
        if ((v += m.v) >= MOD) v -= MOD; 
        return *this; }
    mint& operator-=(const mint& m) { 
        if ((v -= m.v) < 0) v += MOD; 
        return *this; }
    mint& operator*=(const mint& m) { 
        v = (int)((ll)v*m.v%MOD); return *this; }
    mint& operator/=(const mint& m) { return (*this) *= inv(m); }
    friend mint pow(mint a, ll p) {
        mint ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; }
    mint & operator ^=(const int &p) { return (*this) = pow(this, p); }
 
    friend mint inv(const mint& a) { assert(a.v != 0); 
        return pow(a,MOD-2); }
        
    mint operator-() const { return mint(-v); }
    mint& operator++() { return *this += 1; }
    mint& operator--() { return *this -= 1; }
    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
    friend mint operator/(mint a, const mint& b) { return a /= b; }
    friend mint operator^(mint a, const int p) { return pow(a, p); }
};
 
const int MOD = 1000000000000000003, B = 129;
 
typedef mint<MOD,5> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;

const int N = 2e5+7;
vi c[N];
mi pw[N];
vmi h[N], suf[N];
vi sum[N];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    pw[0] = 1;
    for (int i = 1; i < N; ++i) {
        pw[i] = pw[i - 1] * B;
    }

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    vi w(26);
    const int C = 1e13;
    FOR (i, 26) {
        w[i] = rng()%C;
    }

    int n;
    cin >> n;
    V <string> a(n);
    cin >> a;
    auto sor = a;
    each (s, sor) {
        sort(all(s));
    }
    int m = a[0].size();
    if (n <= 2000) {
        int ans = 0;
        FOR (i, n) {
            FOR (j, i) {

                if (sor[i] != sor[j]) {
                    ans += 1337;
                    continue;
                }

                ans += 2;

                int l = 0;
                while (a[i][l] == a[j][l]) {
                    l++;
                }

                int r = m - 1;
                while (a[i][r] == a[j][r]) {
                    r--;
                }

                bool ok = 1;
                for (int p = l; p < r; ++p) {
                    ok &= a[i][p] <= a[i][p + 1];
                }
                if (ok) {
                    ans--;
                    continue;
                }

                ok = 1;
                for (int p = l; p < r; ++p) {
                    ok &= a[j][p] <= a[j][p + 1];
                }
                if (ok) {
                    ans--;
                    continue;
                }

            }
        }
        cout << ans << endl;
    }
    else {

        FOR (i, n) {
            h[i].assign(m + 1, 0);
            suf[i].assign(m + 1, 0);
            FOR (j, m) {
                h[i][j + 1] = h[i][j] * B + a[i][j];
            }
            for (int j = m - 1; j >= 0; --j) {
                suf[i][j] = suf[i][j + 1] + (a[i][j] * pw[m - 1 - j]);
            }
            sum[i].assign(m + 1, 0);
            FOR (j, m - 1) {
                sum[i][j + 1] = sum[i][j] + (a[i][j] > a[i][j + 1]);
            }
        }

        auto solve = [&] (vi who) {
            int n = who.size();
            FOR (i, n) {
                c[i].clear();
            }
            for (int l = 0; l < m; ++l) {
                for (int r = l + 1; r < m; ++r) {

                    int right = m - 1 - r;
                    unordered_map <ll, int> kek;
                    FOR (i, n) {
                        int num = who[i];
                        if (sum[num][r] == sum[num][l]) {
                            mi H = h[num][l] * pw[right] + suf[num][r + 1];
                            kek[H.v] = i;
                        }
                    }   
                    FOR (i, n) {
                        int num = who[i];
                        if (sum[num][r] != sum[num][l]) {
                            mi H = h[num][l] * pw[right] + suf[num][r + 1];
                            if (kek.count(H.v)) {
                                c[kek[H.v]].app(i);
                            }
                        }
                    }

                }
            }
            int ans = n * (n - 1);
            FOR (i, n) {
                sort(all(c[i]));
                ans -= unique(all(c[i])) - c[i].begin();
            }
            return ans;
        };

        map <string, vi> who;
        FOR (i, n) {
            who[sor[i]].app(i);
        }
        int ans = 0;
        int bad = n * (n - 1) / 2;
        each (E, who) {
            ans += solve(E.y);
            int sz = E.y.size();
            bad -= sz * (sz - 1) / 2;
        }
        cout << ans + bad * 1337 << endl;
    }
}