#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 2400;
char s[maxn], r[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k >> (s + 1);
        for(int i = 1; i < k; i += 1){
            r[2 * i - 1] = '(';
            r[2 * i] = ')';
        }
        for(int i = 2 * k - 1; i < n / 2 + k; i += 1) r[i] = '(';
        for(int i = n / 2 + k; i <= n; i += 1) r[i] = ')';
        vector<pair<int, int>> ans;
        for(int i = 1; i <= n; i += 1) if(s[i] != r[i]){
            int j = i;
            while(s[j] != r[i]) j += 1;
            ans.push_back({i, j});
            reverse(s + i, s + j + 1);
        }
        cout << ans.size() << "\n";
        for(auto p : ans) cout << p.first << " " << p.second << "\n";
    }
    return 0;
}