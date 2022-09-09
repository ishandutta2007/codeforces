#include <bits/stdc++.h>
using namespace std;
constexpr bool multiple_test_cases = true;
int main() {
    auto main = [](){
        string name = "Timur", s;
        cin >> s >> s;
        ranges::sort(name);
        ranges::sort(s);
        cout << (name == s ? "YES\n" : "NO\n");
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