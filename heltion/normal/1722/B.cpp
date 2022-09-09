#include <bits/stdc++.h>
using namespace std;
constexpr bool multiple_test_cases = true;
int main() {
    auto main = [](){
        string s, t;
        cin >> s >> s >> t;
        for (char& c : s) if (c == 'G') c = 'B';
        for (char& c : t) if (c == 'G') c = 'B';
        cout << (s == t ? "YES\n" : "NO\n");
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