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

const int N = 2e5+5;
array<ll, 2> a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, w; cin >> n >> w;
        ll hw = w/2 + (w&1);
        for (int i = 0; i < n; i++) {
            cin >> a[i][0]; a[i][1] = i;
        }
        sort(a, a+n, greater<>());
        ll s = 0;
        vector<int> out;
        for (int i = 0; i < n; i++) {
            if (s+a[i][0] > w) continue;
            out.pb(a[i][1]);
            s += a[i][0];
            if (s >= hw) break;
        }
        if (s >= hw && s <= w) {
            cout << out.size() << "\n";
            for (auto& x : out) cout << x+1 << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
}