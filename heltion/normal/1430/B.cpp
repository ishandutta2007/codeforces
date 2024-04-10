#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000 + 1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int& x : v) cin >> x;
        sort(v.begin(), v.end(), greater<int>());
        LL ans = 0;
        for(int i = 0; i <= k; i += 1) ans += v[i];
        cout << ans << "\n";
    }
    return 0;
}