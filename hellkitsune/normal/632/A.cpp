#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, p;
LL cnt = 0;
string s[50];

int main() {
    cin >> n >> p;
    REP(i, n) cin >> s[i];
    LL ans = 0;
    p /= 2;
    for (int i = n - 1; i >= 0; --i) {
        if ((int)s[i].length() == 4) {
            ans += cnt * 2 * p;
            cnt *= 2;
        } else {
            ans += (cnt * 2 + 1) * p;
            cnt = 2 * cnt + 1;
        }
    }
    cout << ans << endl;
    return 0;
}