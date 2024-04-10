#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[100005];
int a[100000];
int n;
const int MOD = 1e9 + 7;
int cnt[64];

int getInt(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 36;
    if (c == '-') return 62;
    return 63;
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    REP(i, n) a[i] = getInt(s[i]);
    REP(i, 64) {
        cnt[i] = 0;
        REP(j, 64) REP(k, 64) if ((j & k) == i) {
            ++cnt[i];
        }
    }
    int ans = 1;
    REP(i, n) ans = (LL)ans * cnt[a[i]] % MOD;
    printf("%d\n", ans);
    return 0;
}