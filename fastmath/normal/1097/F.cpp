#include<bits/stdc++.h>
using namespace std;
const int N = 100007;
const int V = 7007;
vector <int> pr[V];
bool del[V];
bitset <V> mask[V];
void prec() {
    for (int i = 2; i < V; ++i) {
        if (!del[i]) {
            for (int j = 2 * i; j < V; j += i) del[j] = 1;
            for (int j = i; j < V; j += i) pr[j].push_back(i);
        }   
    }   
    for (int i = V - 1; i >= 1; --i) {
        mask[i][i] = 1;
        for (int j = 2 * i; j < V; j += i) mask[i] ^= mask[j];
    }   
}   
bool get(bitset <V> a, int x) {
    auto t = a & mask[x];
    return t.count() & 1;
}   
bitset <V> a[N];
bitset <V> sh[V];
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    prec();
    for (int i = 1; i < V; ++i) {
        for (int j = 1; j < V; ++j) {
            sh[i][j] = i % j == 0;
        }   
    }   
    int n, q;
    cin >> n >> q;
    for (int ii = 0; ii < q; ++ii) {
        int t; cin >> t;
        if (t == 1) {
            int x, v; cin >> x >> v; a[x] = sh[v];
        }   
        else if (t == 2) {
            int x, y, z; cin >> x >> y >> z; a[x] = a[y] ^ a[z];
        }   
        else if (t == 3) {
            int x, y, z; cin >> x >> y >> z; a[x] = a[y] & a[z];
        }   
        else {
            int x, v; cin >> x >> v; cout << get(a[x], v);
        }   
    }   
    cout << '\n';
}