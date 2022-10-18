#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        string s;
        cin >> s;
        int b1 = 0, b2 = 0;
        int ans = 0;
        for (char c : s) {
            if (c == '(') ++b1;
            else if (c == '[') ++ b2;
            else if (c == ')') {
                if (b1) ++ans, --b1;
            }
            else if (c == ']') {
                if (b2) ++ans, --b2;
            }
        }
        cout << ans << endl;
    }
}