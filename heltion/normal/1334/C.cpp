#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300000;
LL a[maxn], b[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 0; i < n; i += 1) cin >> a[i] >> b[i];
        LL ans = 0;
        for(int i = 0; i < n; i += 1) ans += max(a[i] - b[(i + n - 1) % n], 0LL);
        LL pans = LLONG_MAX;
        for(int i = 0; i < n; i += 1) pans = min(a[i] - max(a[i] - b[(i + n - 1) % n], 0LL), pans);
        cout << ans + pans << "\n";
    }
    return 0;
}