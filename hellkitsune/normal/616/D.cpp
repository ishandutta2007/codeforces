#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int cnt[1000001] = {};
int tot = 0;
int from = 0, to = -1;
int a[500000];

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", a + i);
    int j = 0;
    REP(i, n) {
        if (++cnt[a[i]] == 1) {
            ++tot;
        }
        while (tot > k) {
            if (--cnt[a[j]] == 0) {
                --tot;
            }
            ++j;
        }
        if (i - j > to - from) {
            to = i + 1;
            from = j + 1;
        }
    }
    printf("%d %d\n", from, to);
    return 0;
}