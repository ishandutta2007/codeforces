#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
string s[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    int bound = n + 5;
    forn(i, n) {
        cin >> s[i];
        if (bound > n) forn(j, m + 2) if (s[i][j] == '1') {
            bound = i;
        }
    }
    int le = 0, ri = int(1e9);
    int ans = 0;
    for (int i = n - 1; i >= bound; --i) {
        int mn = 12341234;
        int mx = -12341234;
        forn(j, m + 2) if (s[i][j] == '1') {
            mn = min(mn, j);
            mx = max(mx, j);
        }
        int nle = -1, nri = -1;
        if (mn == 12341234) {
            nle = min(le + 1, ri + m + 2);
            nri = min(ri + 1, le + m + 2);
        } else if (i != bound) {
            nle = min(le + 2 * mx + 1, ri + m + 2);
            nri = min(ri + 2 * (m + 1 - mn) + 1, le + m + 2);
        } else {
            ans = min(le + mx, ri + m + 1 - mn);
        }
        le = nle;
        ri = nri;
    }
    cout << ans << endl;
    return 0;
}