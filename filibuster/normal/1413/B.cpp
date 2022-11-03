#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int B = 350;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m)), b(m, vector<int>(n));
    vector<int> c(n * m, -1), d(n * m, -1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;
            c[a[i][j]] = j;
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> b[i][j];
            b[i][j]--;
            d[b[i][j]] = i;
        }
    }

    vector<int> p(m, -1);
    for(int i = 0; i < m; i++) {
        p[i] = d[a[0][i]];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << b[p[j]][i] + 1 << ' ';
        cout << endl;
    }
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}