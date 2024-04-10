#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int t, n;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> s;
        int mask = 0;
        n = s.size();
        int ok100001 = (s[0] == '1');
        for (int i = 1; i + 1 < n; ++i)
            ok100001 &= (s[i] == '0');
        ok100001 &= (s.back() <= '1');
        if (ok100001) {
            for (int i = 0; i < n - 2; ++i) cout << 9;
            cout << "\n";
            continue;
        }
        for (int i = 0; i < n; ++i)
            mask ^= 1 << (s[i] - 48);
        for (int i = n - 1; i >= 0; --i) {
            mask ^= 1 << (s[i] - 48);
            if (s[i] == '0')
                continue;
            int popcnt = __builtin_popcount(mask);
            if (popcnt > n - i) continue;
            if (popcnt % 2 != (n - i) % 2)
                continue;
            if (popcnt < n - i || (popcnt == n - i && __builtin_ctz(mask) < s[i] - 48)) {
                int curdigit = s[i] - 48 - 1;
                if (popcnt == n - i)
                    for (; curdigit >= 0; --curdigit)
                        if (mask & (1 << curdigit))
                            break;
                s[i] = curdigit + '0';
                mask ^= 1 << curdigit;
                for (int j = i + 1; j < n; ++j) {
                    curdigit = 9;
                    if (__builtin_popcount(mask) == n - j)
                        for (; curdigit >= 0; --curdigit)
                            if (mask & (1 << curdigit))
                                break;
                    s[j] = curdigit + '0';
                    mask ^= 1 << curdigit;
                }
                break;
            }
        }
        cout << s << "\n";
    }
}