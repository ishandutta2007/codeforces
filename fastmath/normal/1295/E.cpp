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
const int N = 2e5 + 7, INF = 1e18 + 7;
int p[N], a[N], tree[N << 2], prop[N << 2], pos[N];
void gap(int v, int x) {
    tree[v] += x;
    prop[v] += x;
}   
void push(int v) {
    gap(v * 2 + 1, prop[v]);
    gap(v * 2 + 2, prop[v]);
    prop[v] = 0;
}   
void relax(int v) {
    tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
}   
void add(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl)
        return;
    if (l <= tl && tr <= r) {
        gap(v, x);
        return;
    }   
    int tm = (tl + tr) >> 1;
    push(v);
    add(v * 2 + 1, tl, tm, l, r, x);
    add(v * 2 + 2, tm + 1, tr, l, r, x);
    relax(v);
}   
/*
int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
        return INF;
    if (l <= tl && tr <= r)
        return tree[v];
    push(v);
    int tm = (tl + tr) >> 1;
    return min(get(v * 2 + 1, tl, tm, l, r), get(v * 2 + 2, tm + 1, tr, l, r));
}
*/  
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }   
    for (int i = 0; i < n; ++i) {
        cin >> a[p[i]];
    }
    for (int i = 1; i <= n; ++i) { 
        add(0, 1, n - 1, 0, pos[i], a[i]);

        //cout << "add " << pos[i] << ' ' << a[i] << '\n';

    }   
    int ans = tree[0];
    for (int i = n; i; --i) {
        add(0, 1, n - 1, 0, pos[i], -a[i]);

        //cout << "add " << pos[i] << ' ' << -a[i] << '\n';

        add(0, 1, n - 1, pos[i] + 1, n, a[i]);

        //cout << "add " << pos[i] + 1 << ' ' << a[i] << '\n';

        ans = min(ans, tree[0]);
        //cout << i << ' ' << tree[0] << '\n';
    }   
    cout << ans << '\n';    
}