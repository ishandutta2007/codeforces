#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 20000 + 1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int m, k;
        cin >> m >> k;
        vector<int> a(k + 1);
        for(int i = 1; i <= k; i += 1)
            cin >> a[i];
        int mx = *max_element(a.begin(), a.end());
        int L = 1, R = 30000;
        while(L < R){
            int M = (L + R) >> 1;
            int mmx = (M + 1) / 2 * M;
            int mm = mmx + (M + 1) / 2 * (M / 2);
            if(mmx >= mx and mm >= m) R = M;
            else L = M + 1;
        }
        int n = L;
        cout << n << "\n";
        vector<vector<int>> ans(n, vector<int>(n));
        vector<pair<int, int>> vpL, vpR, vpM;
        for(int i = 0; i < n; i += 1)
            for(int j = 0; j < n; j += 1){
                if((i & 1) and (j & 1)) continue;
                if(i & 1) vpL.push_back({i, j});
                else if(j & 1) vpR.push_back({i, j});
                else vpM.push_back({i, j});
            }
        vector<int> p;
        for(int i = 1; i <= k; i += 1) p.push_back(i);
        sort(p.begin(), p.end(), [&](const int& x, const int& y){
            return a[x] > a[y];
        });
        for(int i : p){
            if(vpL.size() < vpR.size()) swap(vpL, vpR);
            for(int j = 0; j < a[i]; j += 1){
                if(not vpL.empty()){
                    ans[vpL.back().first][vpL.back().second] = i;
                    vpL.pop_back();
                }
                else{
                    ans[vpM.back().first][vpM.back().second] = i;
                    vpM.pop_back();
                }
            }
        }
        for(auto r : ans){
            for(int c : r) cout << c << " ";
            cout << "\n";
        }
    }
    return 0;
}