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
const int N = 1007;
int n, m;
string a[N];
vector <ii> v = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
bool em[2];
bool used[N][N];
void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || used[i][j] || a[i][j] == '.')
        return;
    used[i][j] = 1;
    for (auto e : v) {
        int x = i + e.f, y = j + e.s;
        dfs(x, y);
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   

    for (int i = 0; i < n; ++i) {
        int l = N, r = -1;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '#') {
                l = min(l, j);
                r = max(r, j);
            }   
        }   

        em[0] |= r == -1;

        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.' && l <= j && j <= r) {
                cout << -1 << endl;
                exit(0);
            }   
        }   
    }   

    for (int j = 0; j < m; ++j) {
        int l = N, r = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i][j] == '#') {
                l = min(l, i);
                r = max(r, i);
            }   
        }   

        em[1] |= r == -1;

        for (int i = 0; i < n; ++i) {
            if (a[i][j] == '.' && l <= i && i <= r) {
                cout << -1 << endl;
                exit(0);
            }   
        }   
    }   

    if (em[0] ^ em[1]) {
        cout << -1 << endl;
        exit(0);
    }   

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!used[i][j] && a[i][j] == '#') {
                ++ans;
                dfs(i, j);
            }   
        }   
    }   
    cout << ans << endl;
}