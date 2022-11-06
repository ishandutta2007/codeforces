#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define double long double

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int ms = 1e5+5;
const int inf = 0x3f3f3f3f;

map<int, ll> dic;
int n;
int a[ms];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    // memset(dp, -1, sizeof dp);
    // ans[0] = 0;
    // ans[1] = -1;
    // for(int i = 2; i < ms; i++) {
    //     if(i % 2 == 0) ans[i] = min(-ans[i-2]-2, ans[i-2]);
    //     else ans[i] = max(min(-ans[i-2]-2, ans[i-2]), -ans[i-1]-1);
    //     // for(int j = 0; j < i; j++) {
    //     //     int dif = i-j;
    //     //     if(dif % 2 == 1 && i%2 == 0) continue;
    //     //     int k = -ans[j]-dif;
    //     //     if(k > ans[i]) {
    //     //         cout << i << ' ' << j << ' ' << ans[i] << ' ' << k << endl;
    //     //     }
    //     // }
    //     // cout << i << " = " << ans[i] << endl;
    // }
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        dic.clear();
        ll ans = 0;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) {
            ans += (n-i+1)*dic[a[i]];
            dic[a[i]] += i;
        }
        cout << ans << endl;
    }
    return 0;
}