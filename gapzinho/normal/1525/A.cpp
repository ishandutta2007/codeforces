#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

typedef long long ll;

const int ms = 2e5+5;



int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        int ans = 0x3f3f3f3f;
        for(int i = 1; i <= 1000000; i++) {
            int w = 100 - k;
            // cout << i*100 << ' ' << k*i << ' ' << k << endl;
            if((i*100 - k*i) % k != 0) continue;
            int x = (i*100 - k*i)/k;
            // if(i == 3) cout << w << ' ' << x << endl;
            if(x*100 != (x+i)*w) continue;
            ans = min(ans, i+x);
        }
        cout << ans << endl;
    }
    return 0;
}