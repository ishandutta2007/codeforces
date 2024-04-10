#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000 + 1;
LL a[maxn];
LL pre[maxn], suf[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    for(LL i = 1; i <= n; i += 1) cin >> a[i];
    for(LL i = 1; i <= n; i += 1){
        pre[i] = pre[i - 1] + min(d + r3 + r1 * a[i], 3 * d + min(r1 + r2, r1 * (a[i] + 2)));
        if(i >= 2) pre[i] = min(pre[i], pre[i - 2] + 4 * d + min(r1 + r2, r1 * (a[i] + 2)) + min(r1 + r2, r1 * (a[i - 1] + 2)));
    }
    for(LL i = n; i >= 1; i -= 1){
        if(i == n) suf[i] = min(r3 + r1 * a[i], 2 * d + min(r1 + r2, r1 * (a[i] + 2)));
        else suf[i] = suf[i + 1] + 2 * d + min(r1 + r2, r1 * (a[i] + 2));
    }
    LL ans = min(suf[1], pre[n] - d);
    for(int i = 1; i < n; i += 1) ans = min(pre[i] + suf[i + 1], ans);
    cout << ans;
    return 0;
}