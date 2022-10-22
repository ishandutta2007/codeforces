#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 57;
string a[N];
bool used[N][N];
vector <ii> v = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    memset(used, 0, sizeof used);

    queue <ii> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'B') {
                q.push(mp(i, j));
                used[i][j] = 1;
            }   
        }   
    }   
    while (q.size()) {
        auto p = q.front(); q.pop();

        if (a[p.f][p.s] == '.')
            continue;

        for (auto e : v) {
            int x = p.f + e.f, y = p.s + e.s;
            if (0 <= x && x < n && 0 <= y && y < m && a[x][y] != '#' && !used[x][y]) {
                q.push(mp(x, y));
                used[x][y] = 1;
            }   
        }
    }   

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.' && used[i][j]) {
                a[i][j] = '#';
            }   
        }   
    }   

    memset(used, 0, sizeof used);
    if (a[n - 1][m - 1] == '.') {
        q.push(mp(n - 1, m - 1));
        used[n - 1][m - 1] = 1;
    }
    while (q.size()) {
        auto p = q.front(); q.pop();
        for (auto e : v) {
            int x = p.f + e.f, y = p.s + e.s;
            if (0 <= x && x < n && 0 <= y && y < m && a[x][y] != '#' && !used[x][y]) {
                q.push(mp(x, y));
                used[x][y] = 1;
            }   
        }
    }   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'G' && !used[i][j]) {
                cout << "No" << endl;
                return;
            }   
            if (a[i][j] == 'B' && used[i][j]) {
                exit(1);
            }   
        }   
    }
    cout << "Yes" << endl;
}
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--)
        solve();
}