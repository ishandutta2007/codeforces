#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
LL a[200000], c[200000];
int b[200000], d[200000];
char z;
basic_string<pair<LL, int> > s;
int p[400010];

int main() {
    scanf("%d%d", &n, &m);
    int nn = 0, mm = 0;
    REP(i, n) {
        int x;
        scanf("%d-%c", &x, &z);
        if (i && z - 'a' == b[nn - 1]) {
            a[nn - 1] += x;
        } else {
            a[nn] = x;
            b[nn++] = z - 'a';
        }
    }
    REP(i, m) {
        int x;
        scanf("%d-%c", &x, &z);
        if (i && z - 'a' == d[mm - 1]) {
            c[mm - 1] += x;
        } else {
            c[mm] = x;
            d[mm++] = z - 'a';
        }
    }
    n = nn, m = mm;
    if (m == 1) {
        LL ans = 0;
        REP(i, n) if (b[i] == d[0] && a[i] >= c[0]) {
            ans += a[i] - c[0] + 1;
        }
        cout << ans << endl;
        return 0;
    }
    for (int i = 1; i < m - 1; ++i) s.pb(mp(c[i], d[i]));
    s.pb(mp(-1, -1));
    REP(i, n) s.pb(mp(a[i], b[i]));

    int len = (int)s.length();
    p[0] = 0;
    int ans = 0;
	for (int i = 1; i < len; ++i) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j])
			j = p[j - 1];
		if (s[i] == s[j]) ++j;
		p[i] = j;
		if (j == m - 2) {
            int pos = i - 2 * m + 4;
            if (pos > 0 && pos + m - 2 < n) {
                if (b[pos - 1] == d[0] && a[pos - 1] >= c[0] && b[pos + m - 2] == d[m - 1] && a[pos + m - 2] >= c[m - 1]) {
                    ++ans;
                }
            }
		}
	}
	printf("%d\n", ans);
    return 0;
}