#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[10005], z[10005];
int n, m;

int main() {
    scanf("%s", s);
    n = strlen(s);
    scanf("%d", &m);
    REP(query, m) {
        int from, to, k;
        scanf("%d%d%d", &from, &to, &k), --from, --to;
        int len = to - from + 1;
        k %= len;
        REP(i, len - k) z[i] = s[from + i];
        REP(i, k) s[from + i] = s[from + len - k + i];
        REP(i, len - k) s[from + k + i] = z[i];
    }
    printf("%s\n", s);
    return 0;
}