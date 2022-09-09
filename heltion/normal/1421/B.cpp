#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200;
char s[maxn][maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 0; i < n; i += 1){
            cin >> s[i];
            for(int j = 0; j < n; j += 1) s[i][j] -= '0';
        }
        vector<pair<int, int>> ans;   
        if(s[0][1]) ans.push_back({1, 2});
        if(s[1][0]) ans.push_back({2, 1});
        if(!s[n - 2][n - 1]) ans.push_back({n - 1, n});
        if(!s[n - 1][n - 2]) ans.push_back({n, n - 1});
        if(ans.size() <= 2){
            cout << ans.size() << "\n";
            for(auto [x, y] : ans) cout << x << " " << y << "\n";
        }
        else{
            vector<pair<int, int>> ans;   
            if(!s[0][1]) ans.push_back({1, 2});
            if(!s[1][0]) ans.push_back({2, 1});
            if(s[n - 2][n - 1]) ans.push_back({n - 1, n});
            if(s[n - 1][n - 2]) ans.push_back({n, n - 1});
            cout << ans.size() << "\n";
            for(auto [x, y] : ans) cout << x << " " << y << "\n";
        }
    }
    return 0;
}