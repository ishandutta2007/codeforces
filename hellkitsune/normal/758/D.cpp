#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, len;
string s;
int a[100];

int main() {
    cin >> n >> s;
    len = int(s.size());
    forn(i, len) {
        a[i] = int(s[i] - '0');
    }
    LL ans = 0;
    LL mul = 1;
    while (len) {
        int best = -1;
        forn(i, len) if (a[i] != 0) {
            LL cur = 0;
            for (int j = i; j < len; ++j) {
                cur = 10 * cur + a[j];
                if (cur >= n) {
                    break;
                }
            }
            if (cur < n) {
                best = i;
                break;
            }
        }
        if (best == -1) {
            best = len - 1;
        }
        LL cur = 0;
        for (int j = best; j < len; ++j) {
            cur = 10 * cur + a[j];
        }
        ans += mul * cur;
        mul *= n;
        len = best;
    }
    cout << ans << endl;
    return 0;
}