#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
struct Quer {
    int t, x, l, c;
};
int m, q;
int sz[N];
Quer d[N];
int get(int p) {
    //cout << "get " << p << '\n';
    int i = lower_bound(sz, sz + m, p + 1) - sz - 1;
    if (d[i].t == 1) {
        return d[i].x;
    }
    else {
        p -= sz[i];
        return get(p % d[i].l);
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> d[i].t;
        if (d[i].t == 1) {
            cin >> d[i].x;
            sz[i + 1] = sz[i] + 1;
        }
        else {
            cin >> d[i].l >> d[i].c;
            sz[i + 1] = sz[i] + d[i].l * d[i].c;
        }
    }   
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int p;
        cin >> p;
        --p;
        cout << get(p) << ' ';
    }       
    cout << '\n';
}