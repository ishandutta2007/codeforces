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
        map<int, int> mp;
        int n;
        cin >> n;
        while (n--) {
            int x;
            cin >> x;
            ++mp[abs(x)];
        }
        int ans = 0;
        for (auto [i, cnt] : mp) {
            if (cnt >= 2)
                ans += i == 0 ? 1 : 2;
            else if (cnt == 1)
                ans += 1;
        }
        cout << ans << endl;
    }
}