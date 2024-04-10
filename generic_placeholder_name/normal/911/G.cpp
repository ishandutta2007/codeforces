#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 5;
constexpr int cnt = 576;
constexpr int blk = N / cnt + 5;

int n, q, l, r;
int8_t a[N], lazy[blk][101], x, y;

void du(int l, int r, int8_t x, int8_t y, int lf, int rt){
    int id = (l - 1) / cnt;
    for(int i = l; i <= min(n, r); i++) a[i] = lazy[id][a[i]];
    for(int i = 1; i <= 100; i++) lazy[id][i] = i;
    for(int i = lf; i <= rt; i++){
        if(a[i] == x) a[i] = y;
    }
}

void update(int8_t* a, int n, int8_t x, int8_t y) {
    for(int i = 0; i < n; i++) {
        a[i] = a[i] == x ? y : a[i];
    }
}

void solve(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i <= blk; i++){
        for(int j = 1; j <= 100; j++){
            lazy[i][j] = j;
        }
    }
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[i] = x;
    }
    cin >> q;
    for(int i = 1; i <= q; i++){
        cin >> l >> r;
        int _x, _y; cin >> _x >> _y;
        x = _x, y = _y;
        int idmin = (l - 1) / cnt;
        int idmax = (r - 1) / cnt;
        if(idmin == idmax) du(cnt * idmin + 1, cnt * (idmax + 1), x, y, l, r);
        else{
            du(cnt * idmin + 1, cnt * (idmin + 1), x, y, l, cnt * (idmin + 1));
            du(cnt * idmax + 1, cnt * (idmax + 1), x, y, cnt * idmax + 1, r);
            update((int8_t*)(lazy[idmin + 1]), 101 * (idmax - idmin - 1), x, y);
        }
    }
    for(int i = 1; i <= n; i++){
        a[i] = lazy[(i - 1) / cnt][a[i]];
        cout << (int)a[i] << ' ';
    }
}

int32_t main() {
    solve();
}