    #include <bits/stdc++.h>
    using namespace std;
    int main(){
        double x1, y1, r1; cin >> x1 >> y1 >> r1;
        double x2, y2, r2; cin >> x2 >> y2 >> r2;
        double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        double ans = 0;
        if(d > r1 + r2)
            ans = (d - r1 - r2) / 2;
        else if(d < r1 - r2)
            ans = (r1 - d - r2) / 2;
        else if(d < r2 - r1)
            ans = (r2 - d - r1) / 2;
        cout << fixed << setprecision(15) << ans;
        return 0;   
    }