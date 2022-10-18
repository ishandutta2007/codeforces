#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[100005];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        if (i == 0) printf("%d %d\n", a[i+1] - a[i], a[n-1] - a[i]);
        else if (i == n-1) printf("%d %d\n", a[i] - a[i-1], a[i] - a[0]);
        else printf("%d %d\n", min(a[i+1] - a[i], a[i] - a[i-1]), max(a[n-1] - a[i], a[i] - a[0]));
    }

    return 0;
}