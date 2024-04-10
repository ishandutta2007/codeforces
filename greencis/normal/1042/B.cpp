#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[8];

int main() {
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 8; ++i)
        a[i] = 100000001;
    cin >> n;
    while (n--) {
        int x, mask = 0;
        string s;
        cin >> x >> s;
        for (int i = 0; s[i]; ++i)
            mask |= (1 << (s[i] - 'A'));
        a[mask] = min(a[mask], x);
    }
    int ans = INT_MAX;
    for (int mask = 1 << 8; mask--; ) {
        int cur = 0, curmask = 0;
        for (int i = 0; i < 8; ++i) {
            if ((mask >> i) & 1) {
                cur += a[i];
                curmask |= i;
            }
        }
        if (curmask == 7)
            ans = min(ans, cur);
    }
    if (ans > 100000000) ans = -1;
    cout << ans << endl;
}