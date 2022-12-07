#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a[100];

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", a + i);
    sort(a, a + n, greater<int>());
    REP(i, n) {
        m -= a[i];
        if (m <= 0) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    return 0;
}