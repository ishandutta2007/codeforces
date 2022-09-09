#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
constexpr LL mod = 998244353;
int a[maxn], b[maxn];
int mp[2][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    for(int j = 1; j <= m; j += 1) cin >> b[j];
    int x = a[n], j = m;
    for(int i = n; i; i -= 1){
        x = a[i] = min(x, a[i]);
        if(a[i] == b[j + 1]) mp[0][j + 1] = i;
        if(a[i] == b[j]){
            mp[1][j] = mp[0][j] = i;
            j -= 1;
        }
    }
    if(x < b[1] or j) cout << 0;
    else{
        LL ans = 1;
        for(int i = 2; i <= m; i += 1) ans = ans * (mp[1][i] - mp[0][i] + 1) % mod;
        cout << ans;
    }
}