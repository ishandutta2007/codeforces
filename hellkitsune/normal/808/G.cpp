#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char s[100005], t[100005];
int p[100005];
int nx[100005][26];
int can[100005], ncan[100005];

int main() {
    scanf("%s%s", s, t);
    n = strlen(s);
    m = strlen(t);
    for (int i = 1; i < m; ++i) {
        int j = p[i - 1];
        while (j > 0 && t[j] != t[i]) {
            j = p[j - 1];
        }
        if (t[j] == t[i]) {
            ++j;
        }
        p[i] = j;
    }
    forn(i, m + 1) {
        if (i > 0) {
            forn(j, 26) {
                nx[i][j] = nx[p[i - 1]][j];
            }
        }
        if (i != m) {
            nx[i][t[i] - 'a'] = i + 1;
        }
    }
    forn(i, m + 1) can[i] = -12341234;
    can[0] = 0;
    forn(i, n) {
        int c = (s[i] == '?' ? -1 : int(s[i] - 'a'));
        forn(j, m + 1) ncan[j] = -12341234;
        if (c == -1) {
            forn(j, m + 1) {
                forn(k, 26) ncan[nx[j][k]] = max(ncan[nx[j][k]], can[j]);
            }
        } else {
            forn(j, m + 1) {
                ncan[nx[j][c]] = max(ncan[nx[j][c]], can[j]);
            }
        }
        ++ncan[m];
        forn(j, m + 1) {
            can[j] = ncan[j];
        }
    }
    int ans = 0;
    forn(i, m + 1) ans = max(ans, can[i]);
    cout << ans << endl;
    return 0;
}