#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

#define gcd __gcd
#define lcm(a, b) a*b/__gcd(a, b)

// returns a vector of length n, containing 1 if a number is prime, else 0.
// runs in O(nlogn) time.
template<typename T>
vector<bool> primesieve(T n) {
    vector<bool> sieve(n, 1);
    for (T i = 2; i < n; i++)
        if (sieve[i])
            for (T j = 2*i; j < n; j += i)
                sieve[j] = 0;
    return sieve;
}


// returns a sorted list of all primes less than or equal to n.
// runs in O(nlogn) time.
template<typename T>
vector<T> primesupto(T n) {
    vector<bool> sieve(n+1, 1);
    for (T i = 2; i <= n; i++)
        if (sieve[i])
            for (T j = 2*i; j <= n; j += i)
                sieve[j] = 0;
    vector<T> out;
    for (T i = 2; i <= n; i++)
        if (sieve[i])
            out.push_back(i);
    return out;
}

// returns a sorted list of all prime factors of n in O(sqrt(n)) time.
template<typename T>
vector<T> primefactors(T n) {
    vector<T> out;
    for (T i = 2; i <= n; i++) {
        if (i >= (T)(sqrt(n))+1)
            i = n;
        if (n%i == 0) {
            out.push_back(i);
            n /= i;
            i--;
        }
    }
    return out;
}

// returns a sorted list of all unique prime factors of n in O(sqrt(n)) time.
template<typename T>
vector<T> uniqueprimefactors(T n) {
    vector<T> out;
    for (T i = 2; i <= n; i++) {
        if (i >= (T)(sqrt(n))+1)
            i = n;
        if (n%i == 0) {
            out.push_back(i);
            while (n%i == 0) n /= i;
        }
    }
    return out;
}

// returns a sorted list of all divisors (>1) of n in O(sqrt(n)) time.
template<typename T>
vector<T> divisors(T n) {
    vector<T> s, e;
    s.push_back(1);
    for (T i = 2; i <= (T)(sqrt(n)); i++)
        if (n%i == 0) {
            s.push_back(i);
            if (i*i != n) e.push_back(n/i);
        }
    for (int i = e.size()-1; i >= 0; i--)
        s.push_back(e[i]);
    s.push_back(n);
    return s;
}

const ll mod = 998244353;

template<typename T>
T modinv(T a, T m) {
    T r = 1, k = m-2;
    while (k) {
        if (k&1) r = (r*a)%m;
        a = (a*a)%m;
        k >>= 1;
    }
    return r%m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll d, q; fin >> d >> q;
    vector<ll> p = divisors(d);
    vector<ll> r = uniqueprimefactors(d);
    ll f[10000], finv[10000];
    f[0] = finv[0] = 1;
    for (ll i = 1; i < 10000; i++) {
        f[i] = (f[i-1]*i)%mod;
        finv[i] = modinv(f[i], mod);
    }
    int n = r.size();
    while (q--) {
        ll u, v; fin >> u >> v;
        ll g = gcd(u, v);
        u /= g; v /= g;
        int pu[15] = {}, pv[15] = {};
        int cv = 0, cu = 0;
        for (int i = 0; i < n; i++) {
            while (u%r[i] == 0) { u /= r[i]; pu[i]++; cv++; }
            while (v%r[i] == 0) { v /= r[i]; pv[i]++; cu++; }
        }
        ll out = (f[cv]*f[cu])%mod;
        for (int i = 0; i < n; i++) {
            out = (out*finv[pu[i]])%mod;
            out = (out*finv[pv[i]])%mod;
        }
        cout << out << "\n";
    }
}