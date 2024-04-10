#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int mod = 1'000'000'007;
int C(int m, int n){
    vector<vector<int>> v(m + 1, vector<int>(n + 1));
    for(int i = 0; i <= m; i += 1)
        for(int j = 0; j <= i and j <= n; j += 1)
            v[i][j] = j ? (v[i - 1][j - 1] + v[i - 1][j]) % mod : 1;
    return v.back().back();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int& x : v) cin >> x;
        sort(v.begin(), v.end(), greater<int>());
        cout << C(count(v.begin(), v.end(), v[k - 1]), count(v.begin(), v.begin() + k, v[k - 1])) << "\n";
    }
    return 0;
}