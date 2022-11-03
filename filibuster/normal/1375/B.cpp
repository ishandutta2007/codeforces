#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 300 + 13;

int a[N][N];

void solve() {
    int n, m;
    cin >> n >> m;

    bool fl = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];

            if(a[i][j]<= 2)
                continue;

            if(a[i][j] > 4) {
                fl = true;
                continue;
            }

            if((i == 0 || i == n - 1) && (j == 0 || j == m - 1) && a[i][j] > 2) {
                fl = true;
                continue;
            }

            if(((i == 0 || i == n - 1) || (j == 0 || j == m - 1)) && a[i][j] > 3) {
                fl = true;
                continue;
            }
        }
    }

    if(fl) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i == 0 || i == n - 1) && (j == 0 || j == m - 1))
                cout << 2 << ' ';
            else if((i == 0 || i == n - 1) || (j == 0 || j == m - 1))
                cout << 3 << ' ';
            else
                cout << 4 << ' ';
        }
        cout << endl;
    }
}

int main() {
    int t = 1;
    cin >> t;

    while(t--)
        solve();
}