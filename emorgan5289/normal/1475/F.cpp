#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 1005;
char a[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j], a[i][j] -= '0';
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                char x; cin >> x; x -= '0'; a[i][j] ^= x;
            }
        for (int i = 0; i < n; i++) {
            if (a[i][0] != a[0][0])
                for (int j = 0; j < n; j++)
                    a[i][j] ^= 1;
        }
        for (int i = 0; i < n; i++)
            debug(vector(a[i], a[i]+n));
        bool ok = 1;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
                ok = ok && a[i][j] == a[i-1][j];
        cout << (ok ? "YES" : "NO") << "\n";
    }
}