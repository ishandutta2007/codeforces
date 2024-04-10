#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m;
        cin >> n >> m;
        vector<int> ans(m);
        vector<int> cnt(n + 1);
        vector<vector<int>> f(m);
        for(int i = 0; i < m; i += 1){
            int k;
            cin >> k;
            f[i].resize(k);
            for(int& x : f[i]) cin >> x;
            ans[i] = f[i][0];
            cnt[ans[i]] += 1;
        }
        int mxi = max_element(cnt.begin(), cnt.end()) - cnt.begin();
        for(int i = 0; i < m and cnt[mxi] > (m + 1) / 2; i += 1)
            if(ans[i] == mxi and (int)f[i].size() >= 2){
                ans[i] = f[i][1];
                cnt[mxi] -= 1;
            }
        if(cnt[mxi] > (m + 1) / 2)
            cout << "NO\n";
        else{
            cout << "YES\n";
            for(int x : ans) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}