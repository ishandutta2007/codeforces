#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, d, b;
int a[100000];
int sum[100005];

int solve(int k) {
    sum[0] = 0;
    forn(i, n) sum[i + 1] = sum[i] + a[i];
    int used = 0, bad = 0;
    forn(i, k) {
        int cur = sum[min((LL)(i + 1) * (d + 1), (LL)n)];
        if (cur - used >= b) {
            used += b;
        } else {
            ++bad;
        }
    }
    return bad;
}

int main() {
    scanf("%d%d%d", &n, &d, &b);
    forn(i, n) scanf("%d", a + i);
    int ans = solve((n + 1) / 2);
    reverse(a, a + n);
    ans = max(ans, solve(n / 2));
    cout << ans << endl;
    return 0;
}