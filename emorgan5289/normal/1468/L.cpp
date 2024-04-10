
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

mt19937 randint(chrono::steady_clock::now().time_since_epoch().count());

// returns a vector of length n, containing 1 if a number is prime, else 0.
// runs in O(nloglogn) time.
vector<bool> primesieve(int n) {
    vector<bool> sieve(n, 1);
    for (int i = 2; i < n; i++)
        if (sieve[i])
            for (int j = 2*i; j < n; j += i)
                sieve[j] = 0;
    return sieve;
}

// returns a sorted list of all primes less than or equal to n.
// runs in O(nloglogn) time.
vector<ll> primesupto(ll n) {
    vector<bool> sieve = primesieve(n+1);
    vector<ll> out;
    for (ll i = 2; i <= n; i++)
        if (sieve[i]) out.push_back(i);
    return out;
}

// checks if a number is prime in O(log^3n) time, randint comes from random.cpp.
bool isprime(ll n) {
    static vector<bool> sieve = primesieve(1000000);
    if (n < sieve.size()) return sieve[n];
    if (n%2 == 0) return false;
    ll d = n-1, r = 0;
    while (d%2 == 0) r++, d >>= 1;
    for (int k = 0; k < 30; k++) {
        __int128_t x = 1, a = uniform_int_distribution<ll>(2, n-2)(randint);
        for (ll i = 1; i <= d; i <<= 1) {
            if (d&i) x = (x*a)%n;
            a = (a*a)%n;
        }
        bool f = 0;
        if (x == 1 || x == n-1) f = 1;
        for (int i = 1; i < r; i++)
            f = f || (x = (x*x)%n) == n-1;
        if (!f) return false;
    }
    return true;
}

// returns a sorted list of all prime factors of n in O(min(n^(1/2), n^(1/4)+log^3(n)+10^5)) time.
// works for n <= 10^18
vector<ll> primefactors(ll n) {
    static vector<ll> small = primesupto(1000000);
    if (isprime(n)) return {n};
    vector<ll> out;
    for (ll p : small) {
        if (p*p > n) break;
        while (n%p == 0)
            n /= p, out.push_back(p);
    }
    if (n == 1 || isprime(n)) {
        out.push_back(n);
        return out;
    }
    __int128_t x = 2, y = 2;
    ll f = 0;
    for (ll z = 1; 1; z <<= 1) {
        y = x;
        for (ll i = 0; i < z; i++)
            if ((f = gcd(ll((x = (x*x+1)%n)-y), n)) > 1) {
                out.push_back(min(f, n/f)), out.push_back(max(f, n/f));
                return out;
            }
    }
    return out;
}

// if n is a prime power, returns that prime. otherwise returns 0, runs in O(log^3(n)) time.
ll primepower(ll n) {
    for (ll k = 1; k < 63; k++) {
        __int128_t p = 1;
        for (ll i = 1ll<<32; i > 0; i /= 2) {
            __int128_t x = 1;
            bool f = 0;
            for (int j = 0; j < k; j++)
                if (f = f || (x *= (p+i)) > n) break;
            if (!f && x <= n) {
                p += i;
                if (x == n && isprime(p)) return p;
            }
        }
    }
    return 0;
}

const int N = 1005;
ll x[N], r[N], y[N];
vector<ll> radj[N];
map<ll, vector<ll>> m, adj;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x[i]; y[i] = x[i];
        r[i] = primepower(x[i]);
        if (r[i]) m[r[i]].pb(x[i]);
    }
    ll s = 0;
    ll odd = 0;
    for (auto& [p, v] : m)
        if (v.size() >= 2) {
            for (int i = 0; i < n; i++)
                if (!r[i] && x[i]%p == 0) {
                    while (x[i]%p == 0) x[i] /= p;
                    radj[i].pb(p), adj[p].pb(i);
                }
            if (v.size() >= 3 && !odd) odd = v[0];
            s += v.size();
        }
    vector<ll> out;
    if (k == 1) return cout << "0\n", 0;
    if (s >= k && (k%2 == 0 || odd)) {
        for (auto& [p, v] : m)
            if (v.size() >= 2) {
                if (out.size() == k-1)
                    out.erase(find(all(out), odd));
                for (auto& i : v)
                    if (out.size() < k) out.pb(i);
            }
    }
    if (s < k) {
        for (auto& [p, v] : m)
            if (v.size() >= 2)
                for (auto& i : v)
                    if (out.size() < k) out.pb(i);
        for (int i = 0; i < n; i++)
            if (x[i] == 1 && out.size() < k) out.pb(y[i]);
        if (out.size() < k) return cout << "0\n", 0;
    } else {
        set<ll> vis;
        for (int i = 0; i < n; i++)
            if (x[i] == 1 && radj[i].size() <= k/2) {
                for (auto& j : radj[i]) {
                    vis.insert(j);
                    for (auto& aaa : m[j])
                        out.pb(aaa);
                }
                out.pb(y[i]);
                break;
            }
        if (out.empty()) return cout << "0\n", 0;
        for (auto& [p, v] : m)
            if (v.size() >= 2 && !vis.count(p))
                for (auto& i : v)
                    if (out.size() < k) out.pb(i);
    }
    for (int i = 0; i < k; i++)
        cout << out[i] << " \n"[i == k-1];
}