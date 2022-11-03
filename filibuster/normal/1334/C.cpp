#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 2e5 + 13;

void solve() {
    int n;
    cin >> n;

    vector<li> a(n), b(n);
    li s = 0, mn = 1e18;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        s += a[i];
    }

    for(int i = 0; i < n; i++) {
        b[i] = min(b[i], a[(i + 1) % n]);
        mn = min(mn, b[i]);
        s -= b[i];
    }

    cout << s + mn << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();


}