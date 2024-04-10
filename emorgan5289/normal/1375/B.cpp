#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (auto& r : a) for (auto& x : r) cin >> x;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                bool x = i == 0 || i == n-1;
                bool y = j == 0 || j == m-1;
                int c;
                if (x && y) {
                    c = 2;
                } else if (x || y) {
                    c = 3;
                } else {
                    c = 4;
                }
                if (a[i][j] > c) {
                    cout << "NO\n"; goto next;
                }
                a[i][j] = c;
            }
        cout << "YES\n";
        for (auto& r : a) {
            for (auto& x : r) 
                cout << x << " ";
            cout << "\n";
        }
        next:;
    }
}