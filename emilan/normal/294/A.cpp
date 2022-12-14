#include <bits/stdc++.h>
using namespace std;

void ioThings() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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

    int n; cin >> n;
    int b[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int m; cin >> m;
    while (m--) {
        int x, y; cin >> x >> y;
        x--, y--;
        if (x)
            b[x - 1] += y;
        if (x != n - 1)
            b[x + 1] += b[x] - y - 1;
        b[x] = 0;
    }
    
    for (int i = 0; i < n; i++)
        cout << b[i] << '\n';

    return 0;
}