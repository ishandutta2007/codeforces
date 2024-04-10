#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 3000 + 1;
LL a[maxn], sum[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        for(int i = 1; i <= n; i += 1)
            for(int j = 1; j <= n; j += 1) sum[i][j] = 0;
        for(int i = 1; i <= n; i += 1)
            for(int j = i + 1; j <= n; j += 1)
                if(a[i] == a[j]) sum[i][j] = 1;
        for(int i = 1; i <= n; i += 1)
            for(int j = 1; j <= n; j += 1) sum[i][j] += sum[i - 1][j];
        for(int i = 1; i <= n; i += 1)
            for(int j = 1; j <= n; j += 1) sum[i][j] += sum[i][j - 1];
        LL ans = 0;
        for(int i = 1; i <= n; i += 1)
            for(int j = i + 1; j <= n; j += 1)if(a[i] == a[j]){
                //[1, i - 1] X [i + 1, j - 1]
                ans += sum[i - 1][j - 1] - sum[i - 1][i];
            }
        cout << ans << "\n";
    }
    return 0;
}