#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 32;
LL cnt[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x;
    LL ans = 0;
    for(cin >> n; n; n -= 1){
        cin >> x;
        x = __builtin_popcount(x);
        ans += cnt[x];
        cnt[x] += 1;
    }
    cout << ans;
    return 0;
}