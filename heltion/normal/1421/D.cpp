#include<bits/stdc++.h>
using namespace std;
using LL = long long;
//1,1
//0,1
//-1,0
//-1,-1
//0,-1
//1,0
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL x, y, c[6], ans = LLONG_MAX;
        cin >> x >> y;
        for(int i = 0; i < 6; i += 1) cin >> c[i];
        {
            LL pans = 0;
            if(x > 0) pans += c[5] * x;
            else pans += c[2] * -x;
            if(y > 0) pans += c[1] * y;
            else pans += c[4] * -y;
            ans = min(ans, pans);
        }
        {
            LL pans = 0;
            if(x > 0) pans += c[0] * x;
            else pans += c[3] * -x;
            if(y > x) pans += c[1] * (y - x);
            else pans += c[4] * (x - y);
            ans = min(ans, pans);
        }
        {
            LL pans = 0;
            if(y > 0) pans += c[0] * y;
            else pans += c[3] * -y;
            if(x > y) pans += c[5] * (x - y);
            else pans += c[2] * (y - x);
            ans = min(ans, pans);
        }
        cout << ans << "\n";
    }
    return 0;
}