#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        LL ans = LLONG_MAX;
        LL mi[2] = {(LL)1E13, (LL)1E13}, sm[2] = {0, 0}, cnt[2] = {0, 0};
        for(int i = 0; i < n; i += 1){
            LL c;
            cin >> c;
            mi[i & 1] = min(mi[i & 1], c);
            sm[i & 1] += c;
            cnt[i & 1] += 1;
            ans = min(ans, mi[0] * (n - cnt[0]) + sm[0] + mi[1] * (n - cnt[1]) + sm[1]);
        }
        cout << ans << "\n";
    }
    return 0;
}