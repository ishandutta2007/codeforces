#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL n, ans = 0;
        cin >> n;
        vector<LL> a(n);
        for(LL& x : a) cin >> x;
        reverse(a.begin(), a.end());
        for(int i = 1; i < n; i += 1) ans += max(a[i] - a[i - 1], 0LL);
        cout << ans << "\n";
    }
    return 0;
}