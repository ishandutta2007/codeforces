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

int n, m, k;
vector<vector<int>> g;
vector<int> dijkstra(int s) {
    vector<int> ret(n, inf);
    ret[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(auto adj: g[p]) {
            if(ret[adj] != inf) continue;
            ret[adj] = ret[p] + 1;
            q.push(adj);
        }
    }
    return ret;
}

P cow[5050];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> s(n);
    REP(i, n) cin >> s[i];
    REP(i, n) s[i]--;
    REP(i, m) cin >> cow[i].first >> cow[i].second;
    REP(i, m) cow[i].first--;
    vector<pair<ll, ll>> l(m, {inf, -1}), r(m, {inf, -1});
    REP(i, m) {
        int sum = 0;
        l[i].second = i;
        r[i].second = i;
        REP(j, n) {
            if(s[j] == cow[i].first) sum++;
            if(sum == cow[i].second) {
                l[i].first = j + 1;
                break;
            }
        }
        sum = 0;
        for(ll j = n - 1; j >= 0; j--) {
            if(s[j] == cow[i].first) sum++;
            if(sum == cow[i].second) {
                r[i].first = n - 1 - j + 1;
                break;
            }
        }
    }
    l.pb({0, -1});
    sort(ALL(l));
    sort(ALL(r));
    ll ans = 0;
    mi ansc = 0;
    if(r[0].first == inf) {
        cout << 0 << " " << 1 << endl;
        return 0;
    }
    vector<pair<int, int>> g(m, {0, 1});
    vector<vector<int>> foo(n, vector<int>(4, 0));
    REP(i, m) {
        foo[cow[i].first][1]++;
    }
    ll idx = m - 1;
    REP(i, l.size()) {
        if(l[i].first == inf) continue;
        if(l[i].second != -1) {
            g[l[i].second].first = 1;
            if(g[l[i].second].second) {
                foo[cow[l[i].second].first][1]--;
                foo[cow[l[i].second].first][3]++;
            } else {
                foo[cow[l[i].second].first][0]--;
                foo[cow[l[i].second].first][2]++;
            }
        }
        while(idx >= 0 && r[idx].first + l[i].first > n) {
            g[r[idx].second].second = 0;
            if(g[r[idx].second].first) {
                foo[cow[r[idx].second].first][3]--;
                foo[cow[r[idx].second].first][2]++;
            } else {
                foo[cow[r[idx].second].first][1]--;
                foo[cow[r[idx].second].first][0]++;
            }
            idx--;
        }
        if(g[l[i].second].first == 1 && g[l[i].second].second == 1) {
            foo[cow[l[i].second].first][3]--;
        } else if(g[l[i].second].first == 1 && g[l[i].second].second == 0) {
            foo[cow[l[i].second].first][2]--;
        } else if(g[l[i].second].first == 0 && g[l[i].second].second == 1) {
            foo[cow[l[i].second].first][1]--;
        } else {
            foo[cow[l[i].second].first][0]--;
        }
        int tmp1 = 1;
        mi tmp2 = 1;
        if(l[i].second == -1) tmp1 = 0;
        REP(j, n) {
            if(j == cow[l[i].second].first) {
                if(foo[j][1] || foo[j][3]) {
                    tmp1++;
                    tmp2 *= (foo[j][1] + foo[j][3]);
                }
            } else {
                if(foo[j][3] >= 2 || (foo[j][3] == 1 && foo[j][1] + foo[j][2]) || (foo[j][1] && foo[j][2])) {
                    tmp1 += 2;
                    mi coe = 0;
                    coe += (foo[j][3] * (foo[j][3] - 1));
                    coe += (foo[j][3] * foo[j][1]);
                    coe += (foo[j][2] * foo[j][1]);
                    coe += (foo[j][2] * foo[j][3]);
                    tmp2 *= coe;
                } else if(foo[j][3] || foo[j][1] || foo[j][2]) {
                    tmp1++;
                    tmp2 *= (2 * foo[j][3] + foo[j][1] + foo[j][2]);
                }
            }
        }
        if(tmp1 > ans) {
            ans = tmp1;
            ansc = tmp2;
        } else if(tmp1 == ans) {
            ansc += tmp2;
        }
        if(g[l[i].second].first == 1 && g[l[i].second].second == 1) {
            foo[cow[l[i].second].first][3]++;
        } else if(g[l[i].second].first == 1 && g[l[i].second].second == 0) {
            foo[cow[l[i].second].first][2]++;
        } else if(g[l[i].second].first == 0 && g[l[i].second].second == 1) {
            foo[cow[l[i].second].first][1]++;
        } else {
            foo[cow[l[i].second].first][0]++;
        }
    }
    cout << ans << " " << ansc << endl;
    return 0;
}