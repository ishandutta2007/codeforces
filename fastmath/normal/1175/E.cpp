#include<bits/stdc++.h>
using namespace std;
#define l first
#define r second
#define ii pair <int, int>
#define app push_back
const int N = 2e5 + 7;
const int LG = 20;
int n, m;
ii a[N], b[N];
bool comp(ii a, ii b) {
    return a.l < b.l || (a.l == b.l && a.r > b.r);
}   
int to[N][LG];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i].l >> a[i].r;
    for (int i = 0; i < m; ++i) cin >> b[i].l >> b[i].r;
    vector <ii> v;
    sort(a, a + n, comp);
    int c = -1;
    for (int i = 0; i < n; ++i){
        if (a[i].r > c) {
            v.app(a[i]);
            c = a[i].r;
        }   
    }   
    n = v.size();
    for (int i = 0; i < n; ++i) a[i] = v[i];
    for (int i = n - 1; i >= 0; --i) {
        int l = i;
        int r = n;
        while (l < r - 1) {
            int m = (l + r) >> 1;
            if (a[m].l > a[i].r) r = m;
            else l = m;
        }   
        to[i][0] = l;
        for (int j = 1; j < LG; ++j) {
            to[i][j] = to[to[i][j - 1]][j - 1];
        }   
    }   
    for (int i = 0; i < m; ++i) {
        int l = -1;
        int r = n;
        while (l < r - 1) {
            int m = (l + r) >> 1;
            if (a[m].l <= b[i].l) l = m;
            else r = m;
        }   
        int u = l;

        if (u == -1 || a[to[u][LG - 1]].r < b[i].r) {
            cout << "-1\n";
            continue;
        }   

        if (b[i].r <= a[u].r) {
            cout << "1\n";
            continue;
        }   
            
        int ans = 1;
        for (int j = LG - 1; j >= 0; --j) {
            if (a[to[u][j]].r < b[i].r) {
                ans += 1 << j;
                u = to[u][j];
            }   
        }   
        cout << ans + 1 << '\n';

    }   
}