#include <bits/stdc++.h>

using namespace std;

int n, k;
int ans = 0;
int sum = 0;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int m;
        cin >> m;
        int pr = -1;
        int f = m;
        int ff = -1;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;

            if (j == 0) {
                ff = x;
            }   

            if (x != pr + 1 && j) {
                f = min(f, j);
            }   
            pr = x;
        }   
        
        if (ff != 1) {
            ans += m - 1;
            sum += m;
        }
        else {
            ans += m - f;
            sum += m - f + 1;
        }
    }

    cout << ans + (sum - 1) << '\n';

    return 0;
}