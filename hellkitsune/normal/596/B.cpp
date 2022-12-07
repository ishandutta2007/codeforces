#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[200000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    LL ans = abs(a[0]);
    for (int i = 1; i < n; ++i) {
        ans += abs(a[i] - a[i - 1]);
    }
    cout << ans << endl;
    return 0;
}