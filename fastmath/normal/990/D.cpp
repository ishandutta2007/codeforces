#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 2007;
bool g[N][N], used[N];
int n;
void dfs(int u, int w) {
    used[u] = 1;
    for (int i = 0; i < n; ++i)
        if (!used[i] && g[u][i] == w)
            dfs(i, w);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int a, b;
    cin >> n >> a >> b;

    if (a != 1 && b != 1) {
        cout << "NO\n";
        exit(0);
    }   

    bool add = 0;
    if (b != 1) {
        add = 1;
        swap(a, b);        
    }   
    for (int i = a - 1; i + 1 < n; ++i)
        g[i][i + 1] = g[i + 1][i] = 1;
    
    int cnt = 0;
    memset(used, 0, sizeof used);
    for (int i = 0; i < n; ++i)
        if (!used[i]) {
            ++cnt;
            dfs(i, 1);
        }   
    if (cnt != a) {
        cout << "NO\n";
        exit(0);
    }   

    cnt = 0;
    memset(used, 0, sizeof used);
    for (int i = 0; i < n; ++i)
        if (!used[i]) {
            ++cnt;
            dfs(i, 0);
        }   
    if (cnt != b) {
        cout << "NO\n";
        exit(0);
    }   

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool t = (g[i][j] ^ add) && (i != j);
            cout << t;
        }   
        cout << endl;
    }   
}