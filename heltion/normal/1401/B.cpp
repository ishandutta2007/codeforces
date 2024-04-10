#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //21, 2;12, -2
    int t;
    for(cin >> t; t; t -= 1){
        LL x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        LL h = min(z1, y2);
        z1 -= h;
        y2 -= h;
        LL ans = h * 2;
        LL n = x1 + y1 + z1;
        ans -= max(0LL, y1 + z2 - n) * 2;
        cout << ans << "\n";
    }
    return 0;
}