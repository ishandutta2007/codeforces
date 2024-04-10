#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18 + 7;
int a[3];
int t[7];
int w[7], w1[3];
int mod(int n) {
    return (n % 7 + 7) % 7;
}   
bool check(int s, int k) {
    for (int i = 0; i < 7; ++i) {
        w[mod(i + s)] = (k - i + 6) / 7;
    }   
    for (int i = 0; i < 3; ++i) w1[i] = 0;
    for (int i = 0; i < 7; ++i) {
        w1[t[i]] += w[i];
    }
    for (int i = 0; i < 3; ++i) {
        if (w1[i] > a[i]) return 0;
    }   
    return 1;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    for (int i = 0; i < 7; ++i) t[i] = 2;
    t[0] = t[3] = t[6] = 0;
    t[1] = t[5] = 1;

    for (int i = 0; i < 3; ++i) cin >> a[i];

    int ans = 0; 
    for (int i = 0; i < 7; ++i) {
        int l = -1;
        int r = INF;
        while (l < r - 1) {
            int m = (l + r) >> 1;
            if (check(i, m)) l = m;
            else r = m;
        }
        ans = max(ans, l);
    }   

    cout << ans << '\n';
}