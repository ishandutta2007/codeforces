#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000;
char s[maxn + 2];
int sum[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        cin >> (s + 1);
        int n = strlen(s + 1);
        for(int i = 1; i <= n; i += 1) sum[i] = sum[i - 1] + s[i] - '0';
        int ans = n;
        for(int i = 0; i <= n; i += 1){
            ans = min(ans, sum[i] + ((n - i) - (sum[n] - sum[i])));
            ans = min(ans, (i - sum[i]) + (sum[n] - sum[i]));
        }
        cout << ans << "\n";
    }
    return 0;
}