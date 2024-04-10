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
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 3e5+7, INF = 1e18;

int tree[N << 2][2][2];

void build(int v, int tl, int tr) {
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            tree[v][i][j] = -INF;

    if (tl == tr)
        return;                

    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm);
    build(v * 2 + 2, tm + 1, tr);
}   

void rel(int &a, int b) {
    a = max(a, b);
}   

void relax(int v) {
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            tree[v][i][j] = -INF;

    int L = v * 2 + 1;
    int R = v * 2 + 2;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            rel(tree[v][i][j], tree[L][i][j]);
            rel(tree[v][i][j], tree[R][i][j]);
            
            for (int k = 0; k < 2; ++k) {
                rel(tree[v][i][k], tree[L][i][j] + tree[R][j ^ 1][k]);
            }   
        }   
    }   
}   

void upd(int v, int tl, int tr, int i, int x) {
    if (tl == tr) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                tree[v][i][j] = -INF;
        tree[v][0][0] = x;
        tree[v][1][1] = -x;
        return;
    }   
    int tm = (tl + tr) >> 1;
    if (i <= tm)
        upd(v * 2 + 1, tl, tm, i, x);
    else
        upd(v * 2 + 2, tm + 1, tr, i, x);
    relax(v);
}   

int get() {
    int ans = -INF;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            rel(ans, tree[0][i][j]);
    return ans;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }   
        build(0, 0, n - 1);
        for (int i = 0; i < n; ++i) {
            upd(0, 0, n - 1, i, a[i]);
        }   
        cout << get() << endl;
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            swap(a[l], a[r]);
            upd(0, 0, n - 1, l, a[l]);
            upd(0, 0, n - 1, r, a[r]);
            cout << get() << endl;
        }   
    }   

}