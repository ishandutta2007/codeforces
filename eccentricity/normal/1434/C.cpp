#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL a, b, c, d;
        cin >> a >> b >> c >> d;
        LL km = c / d;
        LL gd = (2 * a - b * d) / (2 * b * d);
        LL ans = max(a, (km + 1) * a - (km + 1) * km / 2 * b * d);
        if(gd >= 0 and gd <= km) ans = max(ans, (gd + 1) * a - (gd + 1) * gd / 2 * b * d);
        if(gd - 1 >= 0 and gd - 1 <= km) ans = max(ans, gd * a - (gd - 1) * gd / 2 * b * d);
        if(gd + 1 >= 0 and gd + 1 <= km) ans = max(ans, (gd + 2) * a - (gd + 2) * (gd + 1) / 2 * b * d);
        LL X = a - b * c, Y = a - (km + 1) * km / 2 * b * d + km * b * c;
        ans = max(ans, X * (km + 1) + Y);
        if(X > 0) cout << "-1\n";
        else cout << ans << "\n";
    }
    return 0;
}