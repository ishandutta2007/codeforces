#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100000];
int mx = 0;
map<LL, int> cnt;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    LL sum = 0;
    REP(i, n) {
        sum += a[i];
        mx = max(mx, ++cnt[sum]);
    }
    printf("%d\n", n - mx);
    return 0;
}