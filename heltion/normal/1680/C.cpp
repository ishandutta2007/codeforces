#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        int n = s.size(), o = ranges::count(s, '1'), ans = o;
        for (int i = 0, j = 0, z = 0; i < n; i += 1) {
            j = max(i, j);
            while (j < n and z < o) {
                if (s[j] == '0') z += 1;
                else o -= 1;
                j += 1;
                ans = min(ans, max(z, o));
            }
            if (s[i] == '0') z -= 1;
            else o += 1;
            ans = min(ans, max(z, o));
        }
        cout << ans << "\n";
    }
}