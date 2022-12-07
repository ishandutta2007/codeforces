#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

PII a[500000];
int n;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", &a[i].second, &a[i].first);
    sort(a, a + n);
    REP(i, n) swap(a[i].first, a[i].second);
    int bound = -1, ans = 0;
    REP(i, n) if (a[i].first > bound) {
        bound = a[i].second;
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}