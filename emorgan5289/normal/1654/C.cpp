#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
 
        ll n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
 
        ll sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
 
        multiset<ll> p = {sum};
        multiset<ll> q(a.begin(), a.end());
 
        while (!p.empty()) {
            ll x = *--p.end();
            if (x < *--q.end()) break;
            p.erase(--p.end());
            if (q.find(x) != q.end())
                q.erase(q.find(x));
            else {
                p.insert(x/2);
                p.insert((x+1)/2);
            }
        }
 
        cout << (q.empty() ? "YES" : "NO") << "\n";
    }
}