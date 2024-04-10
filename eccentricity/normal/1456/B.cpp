#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000 + 2;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if(n >= 70){
        cout << "1";
        return 0;
    }
    int ans = maxn;
    for(int i = 1; i <= n; i += 1){
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    for(int i = 1; i <= n; i += 1)
        for(int j = i; j <= n; j += 1)
            for(int k = j + 1; k <= n; k += 1){
                if((a[j] ^ a[i - 1]) > (a[j] ^ a[k])){
                    ans = min(k - i - 1, ans);
                }
            }
    if(ans == maxn) cout << -1;
    else cout << ans;
    return 0;
}