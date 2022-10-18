#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,k,a[2005],d[2005];

bool check(int x) {
    d[0] = 0;
    for (int i = 1; i < n; ++i) {
        d[i] = i;
        for (int j = 0; j < i; ++j) {
            if ((ll)abs(a[i] - a[j]) <= ll(i - j) * ll(x))
                d[i] = min(d[i], d[j] + i - j - 1);
        }
    }
    bool good = false;
    for (int i = 0; i < n; ++i)
        good |= d[i] + (n - i - 1) <= k;
    return good;
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; ++i) scanf("%d",a+i);
    int l = 0, r = 2e9;
    while (l < r) {
        int mid = int(((ll)l + (ll)r) >> 1ll);
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d",l);

    return 0;
}