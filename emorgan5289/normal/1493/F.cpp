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

// call randint() for a random integer
mt19937 randint(chrono::steady_clock::now().time_since_epoch().count());

// returns a random integer over [a, b] inclusive
inline int uniform_randint(const int a, const int b) {
    return uniform_int_distribution<int>(a, b)(randint);
}

// returns a random double from 0 to 1
inline double rand01() {
    return uniform_randint(0, INT_MAX)/double(INT_MAX);
}

// randomly and uniformly select k distinct integers in the range [0..n-1]
// runs in O(klog(n/k))
vector<int> random_sample(int k, int n) {
    vector<int> r(k);
    std::iota(r.begin(), r.end(), 0);
    double w = exp(log(rand01())/k);
    int i = k-1;
    while (i < n) {
        i += 1+floor(log(rand01())/log(1-w));
        if (i < n) {
            r[uniform_randint(0, k-1)] = i;
            w *= exp(log(rand01())/k);
        }
    }
    return r;
}

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
vector<ll> primesupto(int n) {
    vector<bool> sieve = primesieve(n+1);
    vector<ll> out;
    for (int i = 2; i <= n; i++)
        if (sieve[i]) out.push_back(i);
    return out;
}

// checks if a number is prime in O(log^3(n)) time, randint comes from random.cpp.
// works for n <= 10^18
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

// if n is a prime power, returns that prime, otherwise returns 0, runs in O(log^3(n)) time.
// works for n <= 10^18
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

// returns a sorted list of all divisors of n in O(sqrt(n)) time.
template<typename T>
vector<T> divisors(T n) {
    vector<T> s, e;
    for (T i = 1; i <= (T)(sqrt(n)); i++)
        if (n%i == 0) {
            s.push_back(i);
            if (i*i != n) e.push_back(n/i);
        }
    for (int i = e.size()-1; i >= 0; i--)
        s.push_back(e[i]);
    return s;
}

// computes Euler's totient function of n in O(sqrt(n)) time.
template<typename T>
T totient(T n) {
    T out = 1, s = sqrt(n);
    for (T i = 2; i <= n; i++) {
        if (i > s) i = n;
        if (n%i == 0) {
            n /= i, out *= i-1;
            while (n%i == 0)
                n /= i, out *= i;
        }
    }
    return out;
}

// computes mobius(i) for i from 0 to n in O(nlogn) time
vector<int> mobiussieve(int n) {
    vector<int> m(n+1, -1), p(n+1, 1);
    m[0] = 0, m[1] = 1;
    for (int i = 2; i <= n; i++)
        if (p[i]) for (int j = 2; j*i <= n; j++) {
            if (j%i) m[i*j] = m[i]*m[j];
            else m[i*j] = 0;
            p[i*j] = 0;
        }
    return m;
}

bool s = 0;
int n, m, r_p;

bool query(int h, int w, int i1, int j1, int i2, int j2) {
    if (min(h, w) == 0) return 1;
    if (s) swap(h, w), swap(i1, j1), swap(i2, j2);
    cout << "? " << h << " " << w << " " << i1+1 << " " << j1+1 << " " << i2+1 << " " << j2+1 << endl;
    int r; cin >> r; return r;
}

void submit(int x) {
    cout << "! " << x << endl;
    exit(0);
}

bool has_period(int p) {
    int w = m/p;
    debug(m, p, w);
    if (s && r_p != n) {
        return query(r_p, p*(w-1), 0, 0, r_p, p);
    }
    if (w&1) return query(n, p*(w/2), 0, 0, 0, p*(w/2)) && query(n, p*(w/2), 0, 0, 0, p*((w/2)+1));
    else return query(n, p*(w/2), 0, 0, 0, p*(w/2)) && query(n, p*((w/2)-1), 0, 0, 0, p*((w/2)+1));
}

int min_period() {
    int w = m, r = m;
    for (int i = 2; i <= m; i++)
        while (r%i == 0) {
            if (has_period(w/i)) w /= i;
            r /= i;
        }
    return w;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    r_p = min_period();
    debug(r_p);
    s = 1; swap(n, m);
    int c = divisors(m/min_period()).size();
    submit(divisors(n/r_p).size()*c);
}