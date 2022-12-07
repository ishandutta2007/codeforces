#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[300005];
int a[300000];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    REP(i, n) a[i] = s[i] - '0';
    LL ans = 0;
    REP(i, n) if (!(a[i] & 1)) {
        if (!(a[i] & 3)) ++ans;
        if (i && !((10 * a[i - 1] + a[i]) & 3)) {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}