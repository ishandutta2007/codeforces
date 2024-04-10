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

template<int MOD, int RT> struct mint {
    static const int mod = MOD;
    static constexpr mint rt() { return RT; } // primitive root for FFT
    int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
    mint() { v = 0; }
    mint(ll _v) { v = (int)((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD; }
    friend bool operator==(const mint& a, const mint& b) { 
        return a.v == b.v; }
    friend bool operator!=(const mint& a, const mint& b) { 
        return !(a == b); }
    friend bool operator<(const mint& a, const mint& b) { 
        return a.v < b.v; }
    friend string ts(mint a) { return to_string(a.v); }

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

const int MOD = 31607;

typedef mint<MOD,5> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;

std::ostream& operator << (std::ostream& o, const mi& a)
{
    cout << a.v;
    return o;
}

vector<vmi> scmb; // small combinations
void genComb(int SZ) {
    scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
    FORI(i,1,SZ) FOR(j,i+1) 
        scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}
 
vmi invs, fac, ifac; // make sure to convert to LL before doing any multiplications ...
void genFac(int SZ) {
    invs.resize(SZ), fac.resize(SZ), ifac.resize(SZ); 
    invs[1] = fac[0] = ifac[0] = 1; 
    FORI(i,2,SZ) invs[i] = mi(-(ll)MOD/i*(int)invs[MOD%i]);
    FORI(i,1,SZ) {
        fac[i] = fac[i-1]*i;
        ifac[i] = ifac[i-1]*invs[i];
    }
}
mi comb(int a, int b) {
    if (a < b || b < 0) return 0;
    assert(a < fac.size());
    return fac[a]*ifac[b]*ifac[a-b];
}

const int N = 21;
int n;
mi read[N][N], a[N][N];

mi tot[N];
mi inm[N][1 << N];

mi solve() {
    /*
    FOR (i, n) {
        FOR (j, n) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    */

    FOR (i, n) {
        tot[i] = 1;
        FOR (j, n) {
            tot[i] *= a[i][j];
        }
    }

    FOR (col, n) {
        FOR (mask, 1 << n) {
            if (mask) {
                int bit = 31 - __builtin_clz(mask);
                inm[col][mask] = inm[col][mask ^ (1 << bit)] * a[bit][col];
            }
            else {
                inm[col][mask] = 1;
            }
        }
    }

    int sum = (1 << n) - 1;

    mi ans = 0;
    FOR (mask, 1 << n) {
        mi f = 1;
        FOR (row, n) {
            if (Bit(mask, row)) {
                f *= tot[row];
            }
        }

        mi cur0 = 0, cur1 = 0;
        if (bp(mask) & 1) {
            cur1 = 1;
        }
        else {
            cur0 = 1;
        }

        FOR (col, n) {
            /*
            mi add = 1;
            FOR (row, n) {
                if (!Bit(mask, row)) {
                    add *= a[row][col];
                }
            }
            */
            mi add = inm[col][sum - mask];
            tie(cur0, cur1) = mp(cur0 + cur1 * add, cur1 + cur0 * add);
        }

        //debug(mask);
        //debug(cur1 * 16);
        //debug(cur0 * 16);
        //debug(f * 16);

        ans += (cur1 - cur0) * f;

        //debug(-ans * 16);
    }
    return ans;
}

signed main() {
    #ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    #else

    #endif
    cin >> n;
    FOR (i, n) {
        FOR (j, n) {
            int x;
            cin >> x;
            read[i][j] = mi(x)/10000;
        }
    }

    mi ans = 0;

    {
    FOR (i, n) {
        FOR (j, n) {
            a[i][j] = read[i][j];
        }
    }
    ans += solve();
    ans += 1;     
    }

    {
    mi p = 1;
    FOR (i, n) {
        FOR (j, n) {
            a[i][j] = read[i][j];
            if (i == j) {
                a[i][j] = 1;
                p *= read[i][j];
            }
        }
    }   
    ans -= solve() * p;
    }

    //debug(ans * 16);

    {
    mi p = 1;
    FOR (i, n) {
        FOR (j, n) {
            a[i][j] = read[i][j];
            if (i + j == n - 1) {
                a[i][j] = 1;
                p *= read[i][j];
            }
        }
    }   
    ans -= solve() * p;   
    }

    //debug(ans * 16);

    {
    mi p = 1;
    FOR (i, n) {
        FOR (j, n) {
            a[i][j] = read[i][j];
            if (i + j == n - 1 || i == j) {
                a[i][j] = 1;
                p *= read[i][j];
            }
        }
    }   
    ans += solve() * p; 
    }

    //debug(ans * 16);

    cout << ans << endl;

    #ifdef LOCAL
    debug(Time);
    #endif
}