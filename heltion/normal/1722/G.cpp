#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr bool multiple_test_cases = true;
int main() {
    auto main = [](){
        int n;
        cin >> n;
        if (n % 4 == 0) {
            for (int i = 0; i < n; i += 1) cout << i << " ";
        }
        if (n % 4 == 1) {
            cout << 0 << " ";
            for (int i = 0; i < n - 1; i += 1) cout << (1 << 30) + i << " ";
        }
        if (n % 4 == 3) {
            for (int i = 0; i < n - 3; i += 1) cout << i << " ";
            cout << (1 << 30) << " ";
            cout << (1 << 29) << " ";
            cout << (1 << 29) + (1 << 30) << " ";
        }
        if (n % 4 == 2) {
            for (int i = 0; i < n - 6; i += 1) cout << i << " ";
            for (int i : {4, 1, 2, 12, 3, 8})
                cout << (1 << 30) + i << " ";
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