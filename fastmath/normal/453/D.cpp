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

int m, t, P;
int K;

int mod(int n, int mod) {
    n %= mod;
    if (n < 0) {
        n += mod;
    }
    return n;
}
int mul(int a, int b, int mod) {
    return (__int128)a*b%mod;
}
int binpow(int a, int p, int mod) {
    int ans = 1;
    FOR (i, 60) {
        if (Bit(p, i)) {
            ans = mul(ans, a, mod);
        }
        a = mul(a, a, mod);
    }
    return ans;
}

// u can set modular arithmetic here
void hadamard(vector<int>& v, int MOD){
    for (int step=K; step > 1; step /= 2){
        for (int start=0; start < K; start += step){
            for (int w=0; w < step/2; w++){
                int F = mod(v[start+w] + v[start+step/2+w], MOD);
                int S = mod(v[start+w] - v[start+step/2+w], MOD);
                v[start + w] = F;
                v[start+step/2+w] = S;
            }
        }
    }
}

/* Usage Example
    vector<int> f((1<<K)), g((1<<K));
    hadamard(f);
    hadamard(g);
    for (int i=0; i < K; i++) f[i] *= g[i];
    hadamard(f);
    for (int i=0; i < K; i++) f[i] /= K;
    // f is ur answer
*/


signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> m >> t >> P;
    K = 1 << m;
    vi a(1 << m);
    cin >> a;
    vi f(m + 1);
    cin >> f;

    vi b(1 << m);
    FOR (i, 1 << m) {
        b[i] = f[bp(i)];
    }

    int MOD = K * P;
    hadamard(a, MOD);
    hadamard(b, MOD);

    vi res(K);
    FOR (i, K) {
        res[i] = mul(a[i], binpow(b[i], t, MOD), MOD);
    }

    hadamard(res, MOD);
    FOR (i, K) {
        assert(res[i]%K==0);
        res[i] /= K;
        cout << res[i] << endl;
    }
}