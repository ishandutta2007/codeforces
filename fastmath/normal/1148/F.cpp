#include<bits/stdc++.h>
using namespace std;
#define int long long
#define app push_back
const int LG = 62;
const int N = 3e5 + 7;
int a[N], m[N];
vector <int> t[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i] >> m[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; ; ++j) {
            if ((m[i] >> j) & 1) {
                t[j].app(i);
                break;
            }   
        }   
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    if (sum < 0) {
        for (int i = 0; i < n; ++i) a[i] = -a[i];
    }   
    int ans = 0;    
    for (int i = LG - 1; i >= 0; --i) {
        int sum = 0;
        for (int p : t[i]) sum += a[p];
        if (sum > 0) {
            ans += 1ll << i;
            for (int j = 0; j < n; ++j) {
                if ((m[j] >> i) & 1) a[j] = -a[j];
            }   
        }   
    }   
    cout << ans << '\n';
}