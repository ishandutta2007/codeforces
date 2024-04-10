#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for(auto& r : v)
            for(int& x : r) cin >> x;
        LL ans = 0;
        for(int i = 0; i < n / 2; i += 1)
            for(int j = 0; j < m / 2; j += 1){
                vector<int> w = {
                    v[i][j],
                    v[i][m - 1 - j],
                    v[n - 1 - i][j],
                    v[n - 1 - i][m - 1 - j]
                };
                sort(w.begin(), w.end());
                for(int x : w) ans += abs(x - w[1]);
            }
        if(n & 1)
            for(int j = 0; j < m / 2; j += 1) ans += abs(v[n / 2][j] - v[n / 2][m - 1 - j]);
        if(m & 1)
            for(int i = 0; i < n / 2; i += 1) ans += abs(v[i][m / 2] - v[n - 1 - i][m / 2]);
        cout << ans << "\n";
    }
    return 0;
}