#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;

int n,a[1000005],cnt[1000005],mn[1000005],mx[1000005], mxcnt;

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < 1000005; ++i) mn[i] = 2e9, mx[i] = -2e9;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++cnt[a[i]];
        mxcnt = max(mxcnt, cnt[a[i]]);
        mn[a[i]] = min(mn[a[i]], i + 1);
        mx[a[i]] = max(mx[a[i]], i + 1);
    }

    int anslen = 2e9, ansl, ansr;
    for (int i = 0; i < 1000005; ++i) {
        if (cnt[i] == mxcnt) {
            int len = mx[i] - mn[i] + 1;
            if (len < anslen) {
                anslen = len;
                ansl = mn[i];
                ansr = mx[i];
            }
        }
    }
    cout << ansl << " " << ansr;

    return 0;
}