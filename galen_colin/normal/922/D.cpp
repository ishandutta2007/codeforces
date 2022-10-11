#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define f first
#define s second
 
bool comp(pll a, pll b) {
    return a.f * b.s > b.f * a.s;
}
 
int main() {
    ll n; cin >> n;
    pll ar[n];
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        pll val = make_pair(0, 0);
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 's') {
                ++val.f;
            } else {
                ++val.s;
                
                ans += val.f;
            }
        }
        ar[i] = val;
    }
    sort(ar, ar + n, comp);
    
    // cout << ans << endl;
    
    ll c = 0;
    for (int i = 0; i < n; i++) {
        // cout << ar[i].f << " " << ar[i].s << " " << c << endl;
        ans += ar[i].s * c;
        c += ar[i].f;
    }
    cout << ans << '\n';
}