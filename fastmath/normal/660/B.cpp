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
const int N = 101;
int a[N][4];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;

    vector <ii> pl;
    for (int i = 1; i <= n; ++i) {
        pl.app(mp(i, 0));
        pl.app(mp(i, 3));
    }
    for (int i = 1; i <= n; ++i) {
        pl.app(mp(i, 1));
        pl.app(mp(i, 2));
    }
    for (int i = 1; i <= m; ++i) {
        auto p = pl[i - 1];
        a[p.f][p.s] = i;
    }   

    vector <ii> go;
    for (int i = 1; i <= n; ++i) {
        go.app(mp(i, 1));
        go.app(mp(i, 0));
        go.app(mp(i, 2));
        go.app(mp(i, 3));
    }   
    for (int i = 0; i < go.size(); ++i) {
        int x = a[go[i].f][go[i].s];
        if (x)
            cout << x << ' ';
    }   
    cout << '\n';
}