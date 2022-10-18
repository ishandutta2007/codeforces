#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,a[200005],ans[200005];
pii b[200005];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i)
        scanf("%d",&a[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%d",&b[i].first);
        b[i].second = i;
    }
    sort(a, a + n);
    sort(b, b + m);
    int ai = 0;
    for (int i = 0; i < m; ++i) {
        while (ai < n && a[ai] <= b[i].first)
            ++ai;
        ans[b[i].second] = ai;
    }
    for (int i = 0; i < m; ++i)
        printf("%d ", ans[i]);

    return 0;
}