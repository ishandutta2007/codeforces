#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <cassert>
#include <random>
#include <iomanip>
#include <bitset>
#define FOR(i, n, m) for(ll i = n; i < (int)m; i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 1000000007;
constexpr long double eps = 1e-15;
 
template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> p) {
    os << to_string(p.first) << " " << to_string(p.second);
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    REP(i, v.size()) {
        if(i) os << " ";
        os << to_string(v[i]);
    }
    return os;
}
 
struct modint {
    ll n;
public:
    modint(const ll n = 0) : n((n % mod + mod) % mod) {}
    static modint pow(modint a, int m) {
        modint r = 1;
        while(m > 0) {
            if(m & 1) { r *= a; }
            a = (a * a); m /= 2;
        }
        return r;
    }
    modint &operator++() { *this += 1; return *this; }
    modint &operator--() { *this -= 1; return *this; }
    modint operator++(int) { modint ret = *this; *this += 1; return ret; }
    modint operator--(int) { modint ret = *this; *this -= 1; return ret; }
    modint operator~() const { return (this -> pow(n, mod - 2)); } // inverse
    friend bool operator==(const modint& lhs, const modint& rhs) {
        return lhs.n == rhs.n;
    }
    friend bool operator<(const modint& lhs, const modint& rhs) {
        return lhs.n < rhs.n;
    }
    friend bool operator>(const modint& lhs, const modint& rhs) {
        return lhs.n > rhs.n;
    }
    friend modint &operator+=(modint& lhs, const modint& rhs) {
        lhs.n += rhs.n;
        if (lhs.n >= mod) lhs.n -= mod;
        return lhs;
    }
    friend modint &operator-=(modint& lhs, const modint& rhs) {
        lhs.n -= rhs.n;
        if (lhs.n < 0) lhs.n += mod;
        return lhs;
    }
    friend modint &operator*=(modint& lhs, const modint& rhs) {
        lhs.n = (lhs.n * rhs.n) % mod;
        return lhs;
    }
    friend modint &operator/=(modint& lhs, const modint& rhs) {
        lhs.n = (lhs.n * (~rhs).n) % mod;
        return lhs;
    }
    friend modint operator+(const modint& lhs, const modint& rhs) {
        return modint(lhs.n + rhs.n);
    }
    friend modint operator-(const modint& lhs, const modint& rhs) {
        return modint(lhs.n - rhs.n);
    }
    friend modint operator*(const modint& lhs, const modint& rhs) {
        return modint(lhs.n * rhs.n);
    }
    friend modint operator/(const modint& lhs, const modint& rhs) {
        return modint(lhs.n * (~rhs).n);
    }
};
istream& operator>>(istream& is, modint m) { is >> m.n; return is; }
ostream& operator<<(ostream& os, modint m) { os << m.n; return os; }
 
#define MAX_N 3030303
long long extgcd(long long a, long long b, long long& x, long long& y) {
    long long d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}
long long mod_inverse(long long a, long long m) {
    long long x, y;
    if(extgcd(a, m, x, y) == 1) return (m + x % m) % m;
    else return -1;
}
vector<long long> fact(MAX_N+1, inf);
long long mod_fact(long long n, long long& e) {
    if(fact[0] == inf) {
        fact[0]=1;
        if(MAX_N != 0) fact[1]=1;
        for(ll i = 2; i <= MAX_N; ++i) {
            fact[i] = (fact[i-1] * i) % mod;
        }
    }
    e = 0;
    if(n == 0) return 1;
    long long res = mod_fact(n / mod, e);
    e += n / mod;
    if((n / mod) % 2 != 0) return (res * (mod - fact[n % mod])) % mod;
    return (res * fact[n % mod]) % mod;
}
// return nCk
long long mod_comb(long long n, long long k) {
    if(n < 0 || k < 0 || n < k) return 0;
    long long e1, e2, e3;
    long long a1 = mod_fact(n, e1), a2 = mod_fact(k, e2), a3 = mod_fact(n - k, e3);
    if(e1 > e2 + e3) return 0;
    return (a1 * mod_inverse((a2 * a3) % mod, mod)) % mod;
}
 
using mi = modint;
 
mi mod_pow(mi a, ll n) {
    mi ret = 1;
    mi tmp = a;
    while(n > 0) {
        if(n % 2) ret *= tmp;
        tmp = tmp * tmp;
        n /= 2;
    }
    return ret;
}
 
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int N = 1010100;
int bit[1010100];
void add(int a, int w) {
    a++;
    for (int x = a; x <= N; x += x & -x) bit[x] += w;
}
int sum(int a) {
    a++;
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}

static const int MAX_SIZE = 1 << 18; //segment tree

typedef long long Int;
Int segMax[2 * MAX_SIZE - 1], segAdd[2 * MAX_SIZE - 1];

void add(int a, int b, Int x, int k = 0, int l = 0, int r = MAX_SIZE)
{
    if (r <= a || b <= l) return;
    
    if (a <= l && r <= b){
        segAdd[k] += x;
        return;
    }
    
    add(a, b, x, k * 2 + 1, l, (l + r) / 2);
    add(a, b, x, k * 2 + 2, (l + r) / 2, r);
    segMax[k] = max(segMax[k * 2 + 1] + segAdd[k * 2 + 1], segMax[k * 2 + 2] + segAdd[k * 2 + 2]);
}

Int getMax(int a, int b, int k = 0, int l = 0, int r = MAX_SIZE)
{
    if (r <= a || b <= l) return -(inf * inf);
    if (a <= l && r <= b) return (segMax[k] + segAdd[k]);
    Int left = getMax(a, b, k * 2 + 1, l, (l + r) / 2);
    Int right = getMax(a, b, k * 2 + 2, (l + r) / 2, r);
    
    return (max(left, right) + segAdd[k]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector<pair<ll, ll>> a(n), b(m);
    REP(i, n) cin >> a[i].first >> a[i].second;
    REP(i, m) cin >> b[i].first >> b[i].second;
    sort(ALL(a));
    sort(ALL(b));
    priority_queue<pair<pair<ll, ll>, ll>, vector<pair<pair<ll, ll>, ll>>, greater<pair<pair<ll, ll>, ll>>> q;
    REP(i, n) {
        q.push({{a[i].first, -1}, a[i].second});
    }
    vector<ll> x(p), y(p), z(p);
    REP(i, p) cin >> x[i] >> y[i] >> z[i];
    REP(i, p) q.push({{x[i], y[i]}, z[i]});
    REP(i, m) add(i, i + 1, -b[i].second);
    ll ans = -(inf * inf);
    while(!q.empty()) {
        ll num = q.top().first.first;
        ll num2 = q.top().first.second;
        ll cost = q.top().second;
        q.pop();
        if(num2 == -1) {
            ans = max(ans, getMax(0, m) - cost);
        } else {
            int l = -1, r = m;
            while(r - l > 1) {
                int med = (l + r) / 2;
                if(b[med].first > num2) r = med;
                else l = med;
            }
            add(r, m, cost);
        }
    }
    cout << ans << endl;
    return 0;
}