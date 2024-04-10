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
        int n;
        string s;
        cin >> n >> s;
        string ans(n, ' ');
        for (int i = 0; i < n; ++i) {
            ans[i] = s[i * 2];
        }
        cout << ans << endl;
    }
}