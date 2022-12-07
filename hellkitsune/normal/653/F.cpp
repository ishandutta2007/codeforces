#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[500005];
int n;
int c[1000005], sa[500005], lcp[500005];
LL ord[500005];
const int MASK = (1 << 21) - 1;

void saLcp(char *s, int n) {
    REP(i, n) c[i] = s[i];
    for (int sz = 1; sz < max(2, n); sz <<= 1) {
        REP(i, n) ord[i] = ((((LL)c[i] << 21) | c[i + sz]) << 21) | i;
        sort(ord, ord + n);
        int cnt = 0;
        REP(i, n) {
            c[ord[i] & MASK] = cnt + 1;
            if ((ord[i] >> 21) != (ord[i + 1] >> 21)) ++cnt;
        }
        if (cnt == n) break;
    }
    REP(i, n) sa[c[i]] = i;
    sa[0] = n;
    for (int i = 0, j, k = 0; i < n; lcp[c[i++]] = k) {
        if (c[i] > 0) for (k ? k-- : 0, j = sa[c[i] - 1]; s[i + k] == s[j + k]; k++);
        else k = 0;
    }
    REP(i, n) sa[i] = sa[i + 1], lcp[i] = lcp[i + 1];
}

int bal[500005];
vector<int> _pos[1000005], *pos = _pos + 500002;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%s", &n, s);
    saLcp(s, n);
    bal[0] = 0;
    REP(i, n) {
        bal[i + 1] = bal[i] + (s[i] == '(' ? 1 : -1);
        pos[bal[i + 1]].pb(i);
    }
    LL ans = 0;
    REP(ii, n) {
        int i = sa[ii];
        int bad = bal[i] - 1;
        auto it = lower_bound(pos[bad].begin(), pos[bad].end(), i);
        bad = (it == pos[bad].end() ? n : *it);
        if (i + lcp[ii] >= bad) continue;
        vector<int> &v = pos[bal[i]];
        ans += lower_bound(v.begin(), v.end(), bad) - lower_bound(v.begin(), v.end(), i + lcp[ii]);
    }
    cout << ans << endl;
	return 0;
}