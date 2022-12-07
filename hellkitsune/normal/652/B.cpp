#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[1000], b[1000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    sort(a, a + n);
    int s = 0, t = n - 1;
    REP(i, n) if (i & 1) {
        b[i] = a[t--];
    } else {
        b[i] = a[s++];
    }
    REP(i, n) printf("%d ", b[i]);
    printf("\n");
    return 0;
}