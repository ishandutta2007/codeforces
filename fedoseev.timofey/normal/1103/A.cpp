#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for (auto c : s) {
        if (c == '0') {
            cout << 1 << ' ' << cnt1 + 1 << '\n';
            ++cnt1;
            cnt1 %= 4;
        }
        else {
            if (cnt2 == 0) {
                cout << 3 << ' ' << 1 << '\n';
            }
            else if (cnt2 == 1) {
                cout << 3 << ' ' << 3 << '\n';
            }
            else if (cnt2 == 2) {
                cout << 4 << ' ' << 1 << '\n';
            }
            else {
                cout << 4 << ' ' << 3 << '\n';
            }
            ++cnt2;
            cnt2 %= 4;
        }  
    }
}