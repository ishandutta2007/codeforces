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

template<typename T>
vector<T> primesupto(T n) {
    vector<bool> sieve(n+1, 1);
    for (T i = 2; i <= n; i++)
        if (sieve[i])
            for (T j = 2*i; j < n; j += i)
                sieve[j] = 0;
    vector<T> out;
    for (T i = 2; i <= n; i++)
        if (sieve[i])
            out.push_back(i);
    return out;
}

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

mt19937 randint(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, k, out = 0; fin >> n >> k;
    vector<ll> r(100005);
    for (auto& p : primesupto(100000)) r[p] = randint();
    unordered_map<ll, int> m;
    for (int i = 0; i < n; i++) {
        ll x; fin >> x;
        ll h1 = 0, h2 = 0;
        map<ll, int> s;
        for (auto& p : primefactors(x))
            s[p]++;
        for (auto& p : s) {
            for (int j = 0; j < (p.second%k); j++)
                h1 += r[p.first];
            for (int j = 0; j < (k-(p.second%k))%k; j++)
                h2 += r[p.first];
        }
        debug(x, h1, h2);
        out += m[h2];
        m[h1]++;
    }
    cout << out << "\n";
}