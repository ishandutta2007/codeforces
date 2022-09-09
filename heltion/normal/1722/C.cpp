#include <bits/stdc++.h>
using namespace std;
constexpr bool multiple_test_cases = true;
int main() {
    auto main = [](){
        int n;
        cin >> n;
        vector s(3, vector<string>(n));
        map<string, int> mp;
        for (auto& si : s)
            for (auto& sij : si) {
                cin >> sij;
                mp[sij] += 1;
            }
        for (auto& si : s) {
            int ans = 0;
            for (auto& sij : si) {
                if (mp[sij] == 2) ans += 1;
                if (mp[sij] == 1) ans += 3;
            }
            cout << ans << " ";
        }
        cout << "\n";
    };
/*================================================*/
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    if (multiple_test_cases) {
        cin >> t;
    }
    for (int ti = 1; ti <= t; ti += 1) {
        main();
    }
}