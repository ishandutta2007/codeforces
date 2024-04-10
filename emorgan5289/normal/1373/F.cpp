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

const int N = 2e6+5;
ll a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i], a[i] += a[i-1];
        for (int i = 1; i <= n; i++)
            cin >> b[i], b[i] += b[i-1];
        for (int i = n+1; i <= 2*n; i++)
            a[i] = a[i-n]+a[n], b[i] = b[i-n]+b[n];
        bool ans = a[n] <= b[n];
        ll m = a[1]-b[0];
        for (int i = 2; i <= 2*n; i++) {
            ans = ans && a[i]-b[i] <= m;
            m = min(m, a[i]-b[i-1]);
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
}