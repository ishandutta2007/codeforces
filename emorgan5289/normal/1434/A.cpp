#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 1e5+5;
ll a[6], b[N], p[6];
set<ll> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        for (int j = 0; j < 6; j++)
            s.insert(b[i]-a[j]);
    }
    sort(b, b+n), sort(a, a+6);
    ll ans = inf_ll;
    for (auto& c : s) {
        for (int i = 0; i < 6; i++)
            while (p[i] < n && b[p[i]] < a[i]+c) p[i]++;
        if (p[0] > 0) break;
        ll r = 0;
        for (int i = 0; i < 5; i++)
            if (p[i+1] > p[i]) r = max(b[p[i+1]-1]-a[i], r);
        if (p[5] < n)
            r = max(r, b[n-1]-a[5]);
        debug(c, r);
        ans = min(ans, r-c);
    }
    cout << ans << "\n";
}