#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> a, b;
        for(int i = 0, x, y; i < 2 * n; i += 1){
            cin >> x >> y;
            if(x == 0) a.push_back(abs(y));
            if(y == 0) b.push_back(abs(x));
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        double ans = 0;
        for(int i = 0; i < n; i += 1) ans += hypot(a[i], b[i]);
        cout << ans << "\n";
    }
    return 0;
}