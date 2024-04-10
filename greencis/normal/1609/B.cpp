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

    int n, q;
    string s;
    cin >> n >> q >> s;
    int ans = 0;
    for (int i = 0; i + 3 <= n; ++i)
        ans += s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c';

    auto countAbc = [&](int i) {
        int cur = 0;
        for (int z = -2; z <= 0; ++z) {
            if (i + z < 0 || i + z + 2 >= n)
                continue;
            cur += s[i + z] == 'a' && s[i + z + 1] == 'b' && s[i + z + 2] == 'c';
        }
        return cur;
    };

    while (q--) {
        int pos;
        char c;
        cin >> pos >> c;
        --pos;
        ans -= countAbc(pos);
        s[pos] = c;
        ans += countAbc(pos);
        cout << ans << '\n';
    }
}