#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const ll maxn = 500005;
ll a[maxn], p[maxn];
multiset<ll> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    for (ll i = 0; i < n-n/2; i++)
        cin >> a[i];
    ll x; cin >> x;
    for (ll i = n-n/2-1; i >= 0; i--)
        p[i] = a[i]+p[i+1];
    if (x >= 0)
        cout << (p[0]+x*(n/2) > 0 ? n : -1) << "\n";
    else {
        for (ll i = 0; i < n-n/2; i++) {
            p[i] += i*x + (n%2 == 0 ? x : 0);
            s.insert(p[i]);
        }
        ll k = n/2+1;
        ll j = n-n/2-1;
        ll off = 0;
        while (!s.empty() && *s.begin() + off <= 0) {
            debug(off, s);
            off += x;
            s.erase(s.find(p[j])); j--; k++;
        }
        cout << (s.empty() ? -1 : k) << "\n";
    }
}