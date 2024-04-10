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

const int N = 507;
int link[N];


const int K = 1<<16;

// u can set modular arithmetic here
void ANDConvolution(mi v[K]){
    for (int step=K; step > 1; step /= 2){
        for (int start=0; start < K; start += step){
            for (int w=0; w < step/2; w++){
                v[start+w] += v[start + w + step / 2];
            }
        }
    }
}
void inverseANDConvolution(mi v[K]){
    for (int step=K; step > 1; step /= 2){
        for (int start=0; start < K; start += step){
            for (int w=0; w < step/2; w++){
                v[start+w] -= v[start + w + step / 2];
            }
        }
    }
}
/* Usage Example
    ANDConvolution(f);
    ANDConvolution(g);
    for (int i = 0; i < K; i++) f[i] *= g[i];
    inverseANDConvolution(f);
    f is ur answer
*/


// u can set modular arithmetic here
void ORConvolution(mi v[K]){
    for (int step=K; step > 1; step /= 2){
        for (int start=0; start < K; start += step){
            for (int w=0; w < step/2; w++){
                v[start+step/2+w] += v[start + w];
            }
        }
    }
}

void inverseORConvolution(mi v[K]){
    for (int step=K; step > 1; step /= 2){
        for (int start=0; start < K; start += step){
            for (int w=0; w < step/2; w++){
                v[start+step/2+w] -= v[start + w];
            }
        }
    }
}
/* Usage Example
    ORConvolution(f);
    ORConvolution(g);
    for (int i = 0; i < K; i++) f[i] *= g[i];
    inverseORConvolution(f);
    f is ur answer
*/

mi dp[N][1 << 16];
string s;

mi A[K], B[K], C[K];

int ptr = 0;
int solve(int l, int r) {

    //debug(s.substr(l, r - l + 1));

    int v = ptr;
    ptr++;
    if (l == r) {
        int who = -1, add = -1;

        if (s[l] == 'a') {
            who = 0;
            add = 1;
        }
        else if (s[l] == 'A') {
            who = 0;
            add = 0;
        }
        else if (s[l] == 'b') {
            who = 1;
            add = 1;
        }
        else if (s[l] == 'B') {
            who = 1;
            add = 0;
        }
        else if (s[l] == 'c') {
            who = 2;
            add = 1;
        }
        else if (s[l] == 'C') {
            who = 2;
            add = 0;
        }
        else if (s[l] == 'd') {
            who = 3;
            add = 1;
        }
        else if (s[l] == 'D') {
            who = 3;
            add = 0;
        }
        else {
            assert(s[l] == '?');
        }

        if (who != -1) {
            int foo = 0;
            FOR (mask, 16) {
                if (Bit(mask, who) ^ add) {
                    foo ^= 1 << mask;
                }
            }            
            dp[v][foo] += 1;
        }
        else {  
            FOR (who, 4) {
                FOR (add, 2) {
                    int foo = 0;
                    FOR (mask, 16) {
                        if (Bit(mask, who) ^ add) {
                            foo ^= 1 << mask;
                        }
                    } 
                    dp[v][foo] += 1;
                }
            }
        }

        return v;
    }
    int L = solve(l + 1, link[l] - 1);
    int nextb = link[l] + 2;
    int R = solve(nextb + 1, link[nextb] - 1);

/* Usage Example
    ANDConvolution(f);
    ANDConvolution(g);
    for (int i = 0; i < K; i++) f[i] *= g[i];
    inverseANDConvolution(f);
    f is ur answer
*/





    if (s[nextb - 1] != '&') {

        FOR (i, K) {
            A[i] = dp[L][i];
            B[i] = dp[R][i];
        }
        ORConvolution(A);
        ORConvolution(B);
        for (int i = 0; i < K; i++) {
            C[i] = A[i] * B[i];
        }
        inverseORConvolution(C);
        FOR (i, K) {
            dp[v][i] += C[i];
        }

        /*
        FOR (mask_l, 1 << 16) {
            FOR (mask_r, 1 << 16) {
                int mask = mask_l | mask_r;
                dp[v][mask] += dp[L][mask_l] * dp[R][mask_r];
            }
        }       
        */ 
    }
    if (s[nextb - 1] != '|') {

        FOR (i, K) {
            A[i] = dp[L][i];
            B[i] = dp[R][i];
        }
        ANDConvolution(A);
        ANDConvolution(B);
        for (int i = 0; i < K; i++) {
            C[i] = A[i] * B[i];
        }
        inverseANDConvolution(C);
        FOR (i, K) {
            dp[v][i] += C[i];
        }

        /*
        FOR (mask_l, 1 << 16) {
            FOR (mask_r, 1 << 16) {
                int mask = mask_l & mask_r;
                dp[v][mask] += dp[L][mask_l] * dp[R][mask_r];
            }
        }  
        */
    }
    return v;
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> s;
    int len = s.size();
    vi sk;
    FOR (i, len) {
        if (s[i] == '(') {
            sk.app(i);
        }
        else if (s[i] == ')') {
            assert(sk.size());
            link[sk.back()] = i;
            link[i] = sk.back();
            sk.pop_back();
        }
    }

    int root = solve(0, len - 1);

    int q;
    cin >> q;
    int want = 0;
    int know = 0;
    rep (q) {
        int bit = 0;
        FOR (i, 4) {
            int x; cin >> x;
            if (x) {
                bit ^= 1 << i;
            }
        }
        know ^= 1 << bit;
        int res;
        cin >> res;
        if (res) {
            want ^= 1 << bit;
        }
    }

    mi ans = 0;
    FOR (mask, 1 << 16) {
        bool ok = 1;
        FOR (bit, 16) {
            if (Bit(know, bit)) {
                ok &= Bit(want, bit) == Bit(mask, bit);
            }
        }
        if (ok) {
            ans += dp[root][mask];
        }
    }
    cout << ans << endl;
}