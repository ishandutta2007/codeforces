#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL a, b, k;
        cin >> a >> b >> k;
        map<int, LL> mpa, mpb;
        for(int i = 0, ai; i < k; i += 1){
            cin >> ai;
            mpa[ai] += 1;
        }
        for(int i = 0, bi; i < k; i += 1){
            cin >> bi;
            mpb[bi] += 1;
        }
        LL ans = k * (k - 1) / 2;
        for(auto [x, y] : mpa) ans -= y * (y - 1) / 2;
        for(auto [x, y] : mpb) ans -= y * (y - 1) / 2;
        cout << ans << "\n";
    }
    return 0;
}