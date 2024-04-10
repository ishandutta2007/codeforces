#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, k; fin >> n >> k;
    vector<ll> p = primefactors(n);
    while (p.size() > k) {
        ll x = p.back(); p.pop_back();
        x *= p.back(); p.pop_back();
        p.pb(x);
    }
    if (p.size() < k)
        cout << -1;
    else
        for (auto& x : p)
            cout << x << " ";
    cout << "\n";
}