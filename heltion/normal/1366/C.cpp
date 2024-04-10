#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 30;
int cnt[2][maxn * 2];
int main(){
    int t, n, m, a;
    for(cin >> t; t; t -= 1){
        cin >> n >> m;
        int ans = 0, k = n + m - 2;
        for(int i = 0; i <= k / 2; i += 1) cnt[0][i] = cnt[1][i] = 0;
        for(int i = 0; i < n; i += 1)
            for(int j = 0; j < m; j += 1){
                cin >> a;
                int x = i + j;
                if(x + x > k) x = k - x;
                if(x + x == k) continue;
                cnt[a][x] += 1;
            }
        for(int i = 0; i <= k / 2; i += 1) ans += min(cnt[0][i], cnt[1][i]);
        cout << ans << "\n";
    }
}