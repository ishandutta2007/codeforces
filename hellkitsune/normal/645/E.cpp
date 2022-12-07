#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
char s[1000009];
int pre[26] = {};
int _tot[2000009], *tot = _tot + 1;
const int MOD = 1e9 + 7;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%s", &n, &k, s);
    int m = strlen(s);
    tot[-1] = 0;
    tot[0] = 1;
    memset(pre, -1, sizeof pre);
    REP(i, m) {
        tot[i + 1] = (tot[i] << 1) - tot[pre[s[i] - 'a']];
        if (tot[i + 1] >= MOD) tot[i + 1] -= MOD;
        if (tot[i + 1] < 0) tot[i + 1] += MOD;
        pre[s[i] - 'a'] = i;
    }
    for (int i = m; i < n + m; ++i) {
        int c = 0;
        for (int j = 1; j < k; ++j) if (pre[j] < pre[c]) {
            c = j;
        }
        tot[i + 1] = (tot[i] << 1) - tot[pre[c]];
        if (tot[i + 1] >= MOD) tot[i + 1] -= MOD;
        if (tot[i + 1] < 0) tot[i + 1] += MOD;
        pre[c] = i;
    }
    printf("%d\n", tot[n + m]);
    return 0;
}