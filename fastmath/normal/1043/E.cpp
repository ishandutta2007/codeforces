#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 3e5 + 7;

int n, m;
int a[MAXN], b[MAXN];
vector <int> g[MAXN];
void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }                    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int get(int i, int j) {
    return min(a[i] + b[j], a[j] + b[i]);
}   

bool comp(int i, int j) {
    return a[i] - b[i] < a[j] - b[j];
}

int pref[MAXN], post[MAXN];
int ans[MAXN], per[MAXN];

void solve() {
    for (int i = 0; i < n; ++i) per[i] = i;
    sort(per, per + n, comp);

    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[per[i]];
    for (int i = n - 1; i >= 0; --i) post[i] = post[i + 1] + b[per[i]];

    for (int i = 0; i < n; ++i) {
        int num = per[i];
        ans[num] = pref[i] + post[i + 1] + i * b[num] + (n - i - 1) * a[num];
        for (int v : g[num]) {
            ans[num] -= get(num, v);
        }   
    }   
}

void print() {
    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';
}  

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();
    
    return 0;
}