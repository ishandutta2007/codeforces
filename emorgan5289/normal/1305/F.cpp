#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

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

ll n, a[200005];

ll cost(ll k) {
    ll out = 0;
    for (ll i = 0; i < n; i++)
        out += min((a[i] >= k ? a[i]%k : inf), k-(a[i]%k));
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    srand(time(0));
    fin >> n;
    for (ll i = 0; i < n; i++)
        fin >> a[i];
    set<ll> p; p.insert(2);
    for (ll i = 0; i < 30; i++) {
        if (p.size() > 50) break;
        for (auto& x : primefactors(a[(RAND_MAX+rand())%n]))
            p.insert(x);
        for (auto& x : primefactors(a[(RAND_MAX+rand())%n]+1))
            p.insert(x);
        for (auto& x : primefactors(a[(RAND_MAX+rand())%n]-1))
            p.insert(x);
    }
    debug(p);
    ll out = inf;
    for (auto& x : p)
        out = min(out, cost(x));
    cout << out << "\n";
}