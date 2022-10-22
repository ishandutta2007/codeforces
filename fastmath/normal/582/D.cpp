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

const int N = 3500;
ll P;
int want;

ll divide(vi &a) {
    vi b;
    ll rem = 0;
    each (c, a) {
        rem = rem * 10 + c;
        if (b.size() || rem >= P) {
            b.app(rem/P);
        }
        rem %= P;
    }
    a = b;
    return rem;
}

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

const int MOD = 1e9+7;

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

mi dp[N][N][2][2];
mi inv2;

mi sum(int n) {
    if (n < 0) {
        return 0;
    }
    return mi(n) * (n + 1) * inv2;
}
mi sum(int l, int r) {
    if (r < l) {
        return 0;
    }
    else {
        return sum(r) - sum(l - 1);
    }
}

mi moq(int r) {
    assert(r >= 0);
    if (r < P) {
        int up = P - 1 - (r - P);
        return sum(P - r, P - 1) + P * (up - P + 1);
    }
    else {
        return sum(P - 1 - (r - P));
    }
}

mi ls(int r) {
    return mi(P) * P - moq(r);
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    inv2 = mi(1)/2;
    cin >> P >> want;
    string s;
    cin >> s;
    vi a;
    each (c, s) {
        a.app(c - '0');
    }
    vi inp;
    while (a.size()) {
        inp.app(divide(a));
    }
    reverse(all(inp));
    //debug(inp);

    int len = inp.size();

    if (want > len) {
        cout << 0 << endl;
        exit(0);
    }

    dp[0][0][1][0] = 1; 

    //we go from big digits to small
    //nx - if we want to give 1 to the left digit
    //ha - if we want want to get 1 from the right digit

    FOR (i, len) {
        FOR (j, want + 1) {
            FOR (eq, 2) {
                FOR (nx, 2) {
                    if (dp[i][j][eq][nx].v) {
                        mi val = dp[i][j][eq][nx];
                        FOR (ha, 2) {

                            if (eq) {
                                //debug(inp[i]);
                                //debug(ls(inp[i]));

                                if (nx) {
                                    //P - ha <= a + b < P + inp[i] - ha
                                    dp[i + 1][min(j + ha, want)][0][ha] += val * (ls(P + inp[i] - ha) - ls(P - ha));

                                    //debug("exactly");
                                    //debug(P + inp[i] - ha);
                                    //debug(ls(P + inp[i] - ha + 1) - ls(P + inp[i] - ha));

                                    dp[i + 1][min(j + ha, want)][1][ha] += val * (ls(P + inp[i] - ha + 1) - ls(P + inp[i] - ha));
                                }
                                else {
                                    if (ha <= inp[i]) {
                                        dp[i + 1][min(j + ha, want)][0][ha] += val * ls(inp[i] - ha);
                                        dp[i + 1][min(j + ha, want)][1][ha] += val * (ls(inp[i] - ha + 1) - ls(inp[i] - ha));
                                    }
                                }

                                /*
                                FOR (a, P) {
                                    FOR (b, P) {
                                        if ((a + b + ha >= P) == nx) {
                                            int c = (a + b + ha) % P;
                                            if (c == inp[i]) {
                                                //dp[i + 1][min(j + ha, want)][1][ha] += val;
                                            }
                                            else if (c < inp[i]) {
                                                //dp[i + 1][min(j + ha, want)][0][ha] += val;
                                            }
                                        }
                                    }
                                }    
                                */                            
                            }
                            else {
                                if (nx) {
                                    dp[i + 1][min(j + ha, want)][0][ha] += val * moq(P - ha);
                                }
                                else {
                                    dp[i + 1][min(j + ha, want)][0][ha] += val * ls(P - ha);
                                }
                                
                                /*
                                FOR (a, P) {
                                    FOR (b, P) {
                                        if ((a + b + ha >= P) == nx) {
                                            int c = (a + b + ha) % P;
                                            dp[i + 1][min(j + ha, want)][0][ha] += val;
                                        }
                                    }
                                }
                                */
                                
                            }

                        }                        
                    }
                }
            }
        }
    }

    mi ans = 0;
    FOR (eq, 2) {
        ans += dp[len][want][eq][0];
    }
    cout << ans << endl;
}