#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        int ans = 0;
        for (int k = 0; 1 << k <= n; k++) {
            vector<int> V1, V2;
            for (int i = 1; i <= n; i++) {
                if (i >> k & 1) V1.push_back(i);
                else V2.push_back(i);
            }
            cout << V1.size() << " " << V2.size();
            for (int x : V1) cout << " " << x;
            for (int x : V2) cout << " " << x;
            cout << endl;
            int z; cin >> z, ans = max(ans, z);
        }
        cout << "-1 " << ans << endl;
    }
    return 0;
}