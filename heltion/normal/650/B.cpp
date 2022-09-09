#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 500000;
char s[maxn + 2];
int pre[maxn], suf[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a, b, T, ans = 0;
    cin >> n >> a >> b >> T >> (s + 1);
    for(int i = 1; i <= n; i += 1){
        pre[i] = pre[i - 1] + 1 + (s[i] == 'w' ? b : 0) + (i == 1 ? 0 : a);
        if(pre[i] <= T) ans = i;
    }
    if(ans == n){
        cout << n;
        return 0;
    }
    for(int i = n; i >= 2; i -= 1){
        suf[i] = suf[i + 1] + 1 + (s[i] == 'w' ? b : 0) + a;
        if(suf[i] + pre[1] <= T) ans = max(ans, n + 2 - i);
    }
    for(int i = 1, j = 2; i <= n; i += 1){
        while(suf[j] + pre[i] + min(n + 1 - j, i - 1) * a > T and j <= n + 1) j += 1;
        if(j == n + 2) break;
        ans = max(ans, n + 1 - j + i);
    }
    cout << ans;
    return 0;
}