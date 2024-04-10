#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplaces
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

ll Get() {
    ll x;
    cin >> x;
    if(x == -1) exit(0);
    return x;
}

ll query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    return Get();
}

void solve() {
    int n = Get();

    ll x = query(1, n);
    ll l = 3, r = n-1;
    while(l < r) {
        ll m = l + r + 1 >> 1;
        if(query(1, m) < x) l = m;
        else r = m - 1;
    }
    ll y = x - query(1, l);
    ll k = l + 1;
    ll j = k - y;
    ll z = x - y * (y+1) / 2;

    l = 1, r = n;
    while(l < r) {
        ll m = l + r >> 1;
        if(m * (m-1) / 2 >= z) r = m;
        else l = m+1;
    }

    ll i = j - l;

    cout << "! " << i << " " << j << " " << k << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}