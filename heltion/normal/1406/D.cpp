#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 2;
LL a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1)
        cin >> a[i];
    LL ans = 0;
    for(int i = n; i >= 1; i -= 1){
        a[i] -= a[i - 1];
        if(a[i] > 0 or i == 1) ans += a[i];
    }
    cout << (ans + (ans >= 0)) / 2 << "\n";
    int q;
    for(cin >> q; q; q -= 1){
        int l, r, x;
        cin >> l >> r >> x;
        if(l == 1 or a[l] > 0) ans -= a[l];
        a[l] += x;
        if(l == 1 or a[l] > 0) ans += a[l];
        if(r < n){
            if(a[r + 1] > 0) ans -= a[r + 1];
            a[r + 1] -= x;
            if(a[r + 1] > 0) ans += a[r + 1];
        }
        cout << (ans + (ans >= 0)) / 2 << "\n";
    }
    return 0;
}