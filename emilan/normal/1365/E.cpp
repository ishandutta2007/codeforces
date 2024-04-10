#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll& i : a) cin >> i;
    
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = j; k < n; k++) {
                mx = max(mx, a[i] | a[j] | a[k]);
            }
        }
    }
    cout << mx;

    return 0;
}