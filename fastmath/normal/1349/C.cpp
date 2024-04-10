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
int dist[N][N];

bool type[N * N];
int comp[N][N];

vector <ii> v = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };

bool used[N][N];
void dfs(int i, int j, int c) {
    comp[i][j] = c;
    used[i][j] = 1;
    for (auto e : v) {
        int x = i + e.f, y = j + e.s;
        if (0 <= x && x < n && 0 <= y && y < m && !used[x][y] && a[i][j] == a[x][y]) {
            dfs(x, y, c);
        }   
    }   
}   

bool have(int i, int j) {
    for (auto e : v) {
        int x = i + e.f, y = j + e.s;
        if (0 <= x && x < n && 0 <= y && y < m && a[i][j] == a[x][y]) {
            return 1;
        }   
    }   
    return 0;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    const int INF = 5e18;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            comp[i][j] = -1;
            dist[i][j] = INF;
        }
    int qq;
    cin >> n >> m >> qq;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!used[i][j] && have(i, j)) {
                dfs(i, j, ptr);
                type[ptr] = a[i][j] - '0';
                ++ptr;
            }   
        }   
    }   
    queue <ii> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (comp[i][j] != -1) {
                dist[i][j] = 0;
                q.push(mp(i, j));
            }   
        }            
    }   
    while (q.size()) {
        auto p = q.front();
        q.pop();
        for (auto e : v) {
            int x = p.f + e.f, y = p.s + e.s;
            if (0 <= x && x < n && 0 <= y && y < m && dist[p.f][p.s] + 1 < dist[x][y]) {
                dist[x][y] = dist[p.f][p.s] + 1;
                comp[x][y] = comp[p.f][p.s];
                q.push(mp(x, y));
            }   
        }   
    }   
    while (qq--) {
        int i, j, p;
        cin >> i >> j >> p;
        --i; --j;
        if (p < dist[i][j]) {
            cout << a[i][j] << endl;
        }   
        else {
            cout << (type[comp[i][j]] ^ (p&1)) << endl;
        }   
    }
}