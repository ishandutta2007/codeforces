#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, k, h, ans = 0, rm = 0;
    cin >> n >> h >> k;
    for(int i = 0, a; i < n; i += 1){
        cin >> a;
        if(h - rm >= a) rm += a;
        else{
            LL t = (rm + a - h + k - 1) / k;
            rm = max(rm - t * k, 0LL) + a;
            ans += t;
        }
    }
    cout << ans + (rm + k - 1) / k;
    return 0;
}