#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
constexpr ll mod = 2;
constexpr long double eps = 1e-9;
 
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
 
#define MAX_N 1010101
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

int solve(vector<int> v) {
    int n = (int)v.size();
    int ret = 0;
    REP(i, n) {
        if(v[i] == 0) continue;
        ll c = mod_comb(n - 1, i);
        ret ^= c;
    }
    return ret;
}

ll n, k, m;
vector<int> a;

bool allsame() {
    bool ret = true;
    REP(i, n) if(a[i] != a[0]) ret = false;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> m;
    a.resize(n);
    REP(i, n) cin >> a[i];
    if(k >= n) {
        ll ans = 0;
        if(allsame()) ans = n * m - (n * m) % k;
        cout << n * m - ans << endl;
        return 0;
    }
    stack<pair<int, ll>> st;
    queue<pair<int, ll>> q;
    int cur_col = a[0];
    ll strk = 1;
    FOR(i, 1, n) {
        if(a[i] == cur_col) strk++;
        else {
            q.push({cur_col, strk});
            cur_col = a[i];
            strk = 1;
        }
    }
    q.push({cur_col, strk});
    ll ans = 0;
    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        ans += (now.second - now.second % k) * m;
        now.second %= k;
        if(now.second == 0) {
            while(!st.empty() && !q.empty()) {
                if(st.top().first != q.front().first) break;
                ll sum = st.top().second + q.front().second;
                q.pop();
                ans += (sum - sum % k) * m;
                sum %= k;
                if(sum == 0) {
                    st.pop();
                } else {
                    st.top().second = sum;
                    break;
                }
            }
        } else st.push(now);
    }
    if(st.empty()) {
        cout << 0 << endl;
        return 0;
    }
    deque<pair<int, ll>> rem;
    while(!st.empty()) {
        rem.push_front(st.top());
        st.pop();
    }
    if((int)rem.size() == 1) {
        ans += (rem[0].second * m - (rem[0].second * m) % k);
        cout << n * m - ans << endl;
        return 0;
    }
    if(rem.front().first != rem.back().first) {
        cout << n * m - ans << endl;
        return 0;
    }
    ll rem_front_and_back = 0;
    REP(i, rem.size()) {
        if((int)rem.size() % 2 && i == (int)rem.size() / 2) rem_front_and_back += 0;
        else rem_front_and_back += rem[i].second;
    }
    while(!rem.empty()) {
        if((int)rem.size() == 1) {
            ans += rem.front().second * m - (rem.front().second * m) % k;
            if((rem.front().second * m) % k == 0) rem.pop_front();
            break;
        } else {
            if(rem.front().first != rem.back().first) break;
            ll sum = rem.front().second + rem.back().second;
            ans += (sum - sum % k) * (m - 1);
            if(sum % k == 0) {
                rem.pop_front();
                rem.pop_back();
            } else break;
        }
    }
    if(rem.empty()) ans += rem_front_and_back - rem_front_and_back % k;
    cout << n * m - ans << endl;
    return 0;
}