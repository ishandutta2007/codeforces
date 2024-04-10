#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, x, ans = 0;
        cin >> n >> x;
        vector<int> v(n);
        for(int &x : v) cin >> x;
        sort(v.begin(), v.end(), greater<int>());
        for(LL i = 0, s = 0; i < n; i += 1){
            s += v[i];
            if(s >= x * (i + 1)) ans = max(ans, (int)i + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}