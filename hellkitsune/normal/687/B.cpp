#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[1000000];
int di[100];
bool cov[100] = {};
int cnt = 0;

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", a + i);
    for (int i = 2; i <= k; ++i) {
        if (k % i == 0) {
            int cur = i;
            k /= i;
            while (k % i == 0) {
                cur *= i;
                k /= i;
            }
            di[cnt++] = cur;
        }
    }
    REP(i, n) REP(j, cnt) if (a[i] % di[j] == 0) {
        cov[j] = true;
    }
    bool ok = true;
    REP(i, cnt) if (!cov[i]) {
        ok = false;
    }
    if (ok) printf("Yes\n");
    else printf("No\n");
    return 0;
}