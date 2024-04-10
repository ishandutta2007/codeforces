#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL A, B, C, D;
    cin >> A >> B >> C >> D;
    LL W = B - A, H = C - B, ans = 0;
    if(W < H) swap(W, H);
    for(LL z = C; z <= D; z += 1){
        LL S = z - A - B;
        if(S < 0){
            ans += (H + 1) * (W + 1);
        }
        else if(S < H){
            ans += (H + 1) * (W + 1) - (S + 1) * (S + 2) / 2;
        }
        else if(S < W){
            ans += (W - (S - H) + (W - S)) * (H + 1) / 2;
        }
        else if(S < H + W){
            ans += (H + W - S + 1) * (H + W - S) / 2;
        }
        //cout << z << " " << S << " " << H << " " << W << " " << ans << "\n";
    }
    cout << ans;
    return 0;
}