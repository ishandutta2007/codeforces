#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 3e5 + 13;
const int B = 350;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> lf(n, 0), rg(n, 0);

    lf[0] = a[0];
    int cur = 0;
    for(int i = 1; i < n; i++) {
        lf[i] = min(lf[i - 1], a[i] - cur);
        cur = max(cur, a[i] - lf[i]);
    }

    rg[n - 1] = a[n - 1];
    cur = 0;
    for(int i = n - 2; i >= 0; i--) {
        rg[i] = min(rg[i + 1], a[i] - cur);
        cur = max(cur, a[i] - rg[i]);
    }

    bool ans = true;
    for(int i = 0; i < n; i++) {
        ans = (ans && lf[i] + rg[i] >= a[i]);
    }

    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}