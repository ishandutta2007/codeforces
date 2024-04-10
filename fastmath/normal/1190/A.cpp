#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
    }
    int ans = 0, ptr = 0;
    while (ptr < m) {
        ++ans;
        int d = ptr;
        int w = (a[ptr] - d) / k;                
        while (ptr < m && (a[ptr] - d) / k == w) {
            ++ptr;
        }   
    }   
    cout << ans << '\n';
}