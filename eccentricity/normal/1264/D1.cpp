#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
constexpr int maxn = 2400;
char s[maxn];
int dpl[2][maxn][maxn], dpr[maxn][maxn];
void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> (s + 1);
    int n = strlen(s + 1);
    //dpl 0 i j exactly j
    //dpl 1 i j j before
    dpl[0][0][0] = 1;
    for(int i = 1; i <= n; i += 1)
        for(int j = 0; j <= n; j += 1){
            if(s[i] == '(' or s[i] == '?'){
                if(j) add(dpl[0][i][j], dpl[0][i - 1][j - 1]);
                if(j) add(dpl[0][i][j], dpl[1][i - 1][j - 1]);
            }
            if(s[i] == ')' or s[i] == '?'){
                add(dpl[1][i][j], dpl[0][i - 1][j]);
                add(dpl[1][i][j], dpl[1][i - 1][j]);
            }
        }
    dpr[n + 1][0] = 1;
    for(int i = n; i >= 1; i -= 1)
        for(int j = 0; j <= n; j += 1){
            if(s[i] == ')' or s[i] == '?'){
                if(j) add(dpr[i][j], dpr[i + 1][j - 1]);
            }
            if(s[i] == '(' or s[i] == '?'){
                add(dpr[i][j], dpr[i + 1][j]);
            }
        }
    int ans = 0;
    for(int i = 1; i <= n; i += 1){
        int sum = 0;
        for(int j = n; j >= 1; j -= 1){
            add(sum, dpr[i + 1][j]);
            add(ans, 1LL* dpl[0][i][j] * sum % mod);
        }
    }
    if(false){
        for(int i = 1; i <= n; i += 1)
            for(int j = 0; j <= n; j += 1)
                for(int k = 0; k < 2; k += 1)
                    cout << "dpl" << k << " " << i << " " << j << " " << dpl[k][i][j] << "\n";
        for(int i = 1; i <= n; i += 1)
            for(int j = 0; j <= n; j += 1)
                    cout << "dpr" << i << " " << j << " " << dpr[i][j] << "\n";
    }
    while(ans >= mod) ans -= mod;
    while(ans < 0) ans += mod;
    cout << ans << "\n";
    return 0;
}