#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1){
        int n, m;
        cin >> n >> m;
        vector<int> c(m);
        for(int i = 0, a; i < n; i += 1){
            cin >> a;
            c[a % m] += 1;
        }
        int ans = 0;
        for(int i = 1; i * 2 < m; i += 1){
            if(c[i] or c[m - i]) ans += 1;
            ans += max(abs(c[i] - c[m - i]) - 1, 0);
        }
        if(c[0]) ans += 1;
        if(m % 2 == 0 and c[m / 2]) ans += 1;
        cout << ans << "\n";
    }
    return 0;
}