#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

char a[200005],b[200005];
int ai,bi;
int cnt[2][200005];
ll ans;

int main()
{
    cin >> a + 1 >> b + 1;
    ai = strlen(a + 1);
    bi = strlen(b + 1);
    for (int i = 1; i <= bi; ++i) {
        cnt[0][i] = cnt[0][i-1] + (b[i] == '0');
        cnt[1][i] = cnt[1][i-1] + (b[i] == '1');
    }
    for (int i = 1; i <= ai; ++i) {
        ans += cnt[49 - a[i]][i + bi - ai] - cnt[49 - a[i]][i - 1];
    }
    cout << ans;

    return 0;
}