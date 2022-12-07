#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[1000][8];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%s", s[i]);
    if (n == 1) {
        printf("6\n");
        return 0;
    }
    int worst = 6;
    REP(i, n) for (int j = i + 1; j < n; ++j) {
        int dist = 0;
        REP(k, 6) dist += s[i][k] != s[j][k];
        worst = min(worst, dist);
    }
    printf("%d\n", (worst - 1) / 2);
    return 0;
}