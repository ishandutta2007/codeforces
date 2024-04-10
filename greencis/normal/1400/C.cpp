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
        int x;
        cin >> s >> x;
        int n = s.size();
        string w(n, '1');
        for (int i = 0; s[i]; ++i) {
            if (i - x >= 0 && s[i] == '0') w[i - x] = '0';
            if (i + x < n  && s[i] == '0') w[i + x] = '0';
        }
        string check(n, '0');
        for (int i = 0; i < n; ++i) {
            if (i - x >= 0) check[i] |= w[i - x];
            if (i + x < n)  check[i] |= w[i + x];
        }
        if (check != s) cout << "-1\n";
        else cout << w << '\n';
    }
}