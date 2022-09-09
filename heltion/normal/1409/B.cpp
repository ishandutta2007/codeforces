#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        if(a - x + b - y <= n) cout << x * y << "\n";
        else{
            LL ans = LLONG_MAX;
            if(a - x > n) ans = min(ans, (a - n) * b);
            else ans = min(ans, x * (b - (n - (a - x))));
            if(b - y > n) ans = min(ans, (b - n) * a);
            else ans = min(ans, y * (a - (n - (b - y))));
            cout << ans << "\n";
        }
    }
    return 0;
}