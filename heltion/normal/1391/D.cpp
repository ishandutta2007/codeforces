#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000 + 1;
char s[maxn];
bool p(int j, int k, int m){
    if(m == 1) return true;
    if(m == 2) return (__builtin_popcount(j) + __builtin_popcount(k)) % 2;
    return (__builtin_popcount(j & 3) + __builtin_popcount(k & 3)) % 2
        and (__builtin_popcount(j >> 1) + __builtin_popcount(k >> 1)) % 2;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int x = min(n, m);
    if(x >= 4){
        cout << -1;
        return 0;
    }
    vector<int> v;
    if(n >= 4){
        v.resize(n);
        for(int i = 0; i < n; i += 1){
            string s;
            cin >> s;
            for(char c : s) v[i] = v[i] * 2 + c - '0';
        }
    }
    else{
        v.resize(m);
        for(int i = 0; i < n; i += 1){
            string s;
            cin >> s;
            for(int j = 0; j < m; j += 1) v[j] |= (s[j] - '0') << i;
        }
        swap(n, m);
    }
    vector<vector<int>> dp(n, vector<int>(1 << m, maxn));
    for(int i = 0; i < n; i += 1){
        //cout << v[i] << "\n";
        for(int j = 0; j < (1 << m); j += 1){
            if(i == 0) dp[i][j] = 0;
            else for(int k = 0; k < (1 << m); k += 1) if(p(j, k, m)) dp[i][j] = min(dp[i - 1][k], dp[i][j]);
            dp[i][j] += __builtin_popcount(j ^ v[i]);
            //cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    }
    cout << *min_element(dp.back().begin(), dp.back().end());
    return 0;
}