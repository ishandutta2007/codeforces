#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    for (int len = s.size(); len; len--) {
        for (int i = 0; i + len <= s.size(); i++) {
            string p = s.substr(i, len);
            if (s.find(p, i + 1) != -1) {
                cout << len << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;
    return 0;
}