#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr bool multiple_test_cases = true;
int main() {
    auto main = [](){
        int n;
        cin >> n;
        string s;
        cin >> s;
        LL ans = 0;
        vector<int> diff;
        for (int i = 0; i < n; i += 1) {
            int L = i, R = n - i - 1;
            if (s[i] == 'L') ans += L, diff.push_back(R - L);
            else ans += R, diff.push_back(L - R);
        }
        ranges::sort(diff, greater<int>());
        for (int i = 0; i < n; i += 1)
            cout << (ans += max(diff[i], 0)) << " ";
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