#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,dp[500005],dpmax[500005];
pii a[500005];

int getidx(int x) {
    if (a[n-1].first <= x) return n;
    int L = 0, R = n-1;
    while (L < R) {
        int mid = (L + R) / 2;
        if (a[mid].first > x) R = mid;
        else L = mid + 1;
    }
    return L;
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d",&a[i].first,&a[i].second);
    sort(a,a+n);
    for (int i = n-1; i >= 0; --i) {
        int idx = getidx(a[i].second);
        dp[i] = dpmax[idx] + 1;
        dpmax[i] = max(dp[i], dpmax[i + 1]);
    }
    cout << dpmax[0];

    return 0;
}