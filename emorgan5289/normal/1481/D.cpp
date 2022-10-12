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
int x[N], y[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (a[i][j] == a[j][i] || m&1) {
                    cout << "YES\n" << j+1;
                    for (int k = 0; k < m/2; k++)
                        cout << " " << i+1 << " " << j+1;
                    if (m&1) cout << " " << i+1;
                    cout << "\n";
                    goto next;
                }
        fill(x, x+n, -1), fill(y, y+n, -1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] == 'a') x[j] = i, y[i] = j;
        for (int i = 0; i < n; i++)
            if (min(x[i], y[i]) != -1) {
                cout << "YES\n";
                if ((m/2)&1) cout << x[i]+1 << " ";
                for (int k = 0; k < m/4; k++)
                    cout << i+1 << " " << x[i]+1 << " ";
                cout << i+1;
                for (int k = 0; k < m/4; k++)
                    cout << " " << y[i]+1 << " " << i+1;
                if ((m/2)&1) cout << " " << y[i]+1;
                cout << "\n";
                goto next;
            }
        cout << "NO\n";
        next:;
    }
}