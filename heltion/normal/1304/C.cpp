#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    for(cin >> q; q; q -= 1){
        int n, m, ok = 1, p = 0;
        cin >> n >> m;
        int L = m, H = m;
        for(int i = 0; i < n; i += 1){
            int t, l, h;
            cin >> t >> l >> h;
            L -= (t - p);
            H += (t - p);
            p = t;
            L = max(L, l);
            H = min(H, h);
            if(L > H) ok = 0;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}