#include <bits/stdc++.h>
using namespace std;

void ioThings() {
    ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
}

using ll = long long;
#define debug(x) cerr << #x << ": <" << x << ">\n"
#define sz(x) (int)x.size()
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main() {
    ioThings();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n + n];
        for (int i = 0; i < n + n; i++)
            cin >> a[i];
        sort(a, a + n + n);
        cout << a[n] - a[n - 1] << '\n';
    }

    return 0;
}