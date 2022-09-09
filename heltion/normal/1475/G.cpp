#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
vector<int> d[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 1; i < maxn; i += 1){
        for(int j = i; j < maxn; j += i)
            d[j].push_back(i);
        reverse(d[i].begin(), d[i].end());
    }
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int& x : a) cin >> x;
        sort(a.begin(), a.end());
        vector<int> dp(a.back() + 1);
        for(int x : a)
            for(int y : d[x])
                dp[x] = max(dp[x], dp[y] + 1);
        cout << n - *max_element(dp.begin(), dp.end()) << "\n";
    }
    return 0;
}