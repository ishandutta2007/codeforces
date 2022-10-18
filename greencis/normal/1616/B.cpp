#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        string s;
        cin >> n >> s;
        if (n <= 1 || s[0] == s[1]) {
            cout << s[0] << s[0] << '\n';
            continue;
        }
        int len = n;
        for (int i = 1; i < n; ++i) {
            if (s[i] > s[i - 1]) {
                len = i;
                break;
            }
        }
        s = s.substr(0, len);
        s += string(s.rbegin(), s.rend());
        cout << s << '\n';
    }
}