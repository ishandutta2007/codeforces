#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define double long double

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int ms = 3e5+5;
const int inf = 0x3f3f3f3f;

int a[ms];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        int ans = 1;
        int dif = inf;
        int hi = a[0];
        for(int i = 1; i< n; i++) {
            dif = min(dif, a[i] - a[i-1]);
            hi = max(a[i], hi);
            if(dif >= hi) {
                ans++;
            } else break;
        }
        cout << ans << '\n';
    }
    return 0;
}