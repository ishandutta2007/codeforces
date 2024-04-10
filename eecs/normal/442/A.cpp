#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(0);
    int n; cin >> n;
    set<int> S;
    string z = "RGBYW";
    while (n--) {
        string s; cin >> s;
        S.insert(1 << (z.find(s[0]) + 5) | (1 << (s[1] - '1')));
    }
    vector<int> a(S.begin(), S.end());
    int ans = INT_MAX;
    for (int i = 0; i < 1 << 10; i++) {
        bool ok = true;
        for (int j = 0; j < a.size(); j++) {
            for (int k = j + 1; k < a.size(); k++) {
                if ((i & a[j]) == (i & a[k])) ok = false;
            }
        }
        if (ok) ans = min(ans, __builtin_popcount(i));
    }
    cout << ans << '\n';
    return 0;
}