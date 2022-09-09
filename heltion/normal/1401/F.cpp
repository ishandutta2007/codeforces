#include<bits/stdc++.h>
using namespace std;
using LL = long long;
vector<LL> a[18 + 1];
int re[19], sw[18];
#define tm ((tl + tr) >> 1)
LL sum(int tl, int tr, int n){
    int d = tr - tl + 1, p = tl / d, x = 0;
    for(; d % 2 == 0; d /= 2) x += 1;
    for(int i = x; i < n; i += 1) if(sw[i]) p ^= 1 << (i - x);
    for(int i = x + 1; i <= n; i += 1) if(re[i]) p ^= (1 << (i - x)) - 1;
    return a[x][p];
}
LL sum(int tl, int tr, int l, int r, int n){
    if(tl >= l and tr <= r) return sum(tl, tr, n);
    LL res = 0;
    if(l <= tm) res += sum(tl, tm, l, r, n);
    if(r > tm) res += sum(tm + 1, tr, l, r, n);
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    a[0].resize(1 << n);
    for(LL& x : a[0]) cin >> x;
    for(int i = 0; i < n; i += 1)
        for(int j = 0; j < (int)a[i].size(); j += 2) a[i + 1].push_back(a[i][j] + a[i][j + 1]);
    for(; q; q -= 1){
        int o, x, k, l, r;
        cin >> o;
        if(o == 1){
            cin >> x >> k;
            x -= 1;
            for(int i = 0; i < n; i += 1) if(sw[i]) x ^= 1 << i;
            for(int i = 1; i <= n; i += 1) if(re[i]) x ^= (1 << i) - 1;
            LL d = k - a[0][x];
            for(int j = 0; j <= n; j += 1) a[j][x >> j] += d;
        }
        else if(o == 2){
            cin >> k;
            re[k] ^= 1;
        }
        else if(o == 3){
            cin >> k;
            sw[k] ^= 1;
        }
        else{
            cin >> l >> r;
            cout << sum(0, (1 << n) - 1, l - 1, r - 1, n) << "\n";
        }
    }
    return 0;
}