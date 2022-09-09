#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL n, m;
        cin >> n >> m;
        vector<LL> a(n);
        for(LL& x : a) cin >> x;
        vector<LL> v[2];
        for(int i = 0, b; i < n; i += 1){
            cin >> b;
            v[b - 1].push_back(a[i]);
        }
        for(int i = 0; i < 2; i += 1){
            sort(v[i].begin(), v[i].end(), greater<LL>());
            partial_sum(v[i].begin(), v[i].end(), v[i].begin());
        }
        int ans = INT_MAX;
        for(int i = 0; i <= v[0].size(); i += 1){
            LL rm = m - (i ? v[0][i - 1] : 0);
            if(rm <= 0)
                ans = min(ans, i);
            else{
                auto it = lower_bound(v[1].begin(), v[1].end(), rm);
                if(it == v[1].end()) continue;
                ans = min(ans, 2 * int(it - v[1].begin() + 1) + i);
            }
        }
        cout << (ans == INT_MAX ? -1 : ans) << "\n";
    }
    return 0;
}