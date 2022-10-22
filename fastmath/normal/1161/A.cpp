#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int l[N];
int a[N];
int nn[N];
bool c[N];
int last[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) cin >> a[i];    
    nn[0] = n;
    for (int i = 0; i < k; ++i) {
        nn[i + 1] = nn[i];
        if (!c[a[i]]) {
            c[a[i]] = 1;
            --nn[i + 1];
        }   
    }   

    for (int i = 0; i <= n; ++i) {
        last[i] = -1;
    }   
    for (int i = 0; i < k; ++i) {
        last[a[i]] = i;
    }   

    for (int i = 0; i <= n; ++i) {
        l[i] = k;
    }   
    for (int i = k - 1; i >= 0; --i) {
        l[a[i]] = i;
    }   
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += !c[i];
        if (i > 1) ans += (l[i - 1] > last[i]);
        if (i < n) ans += (l[i + 1] > last[i]);
    }   
    cout << ans << '\n';
}