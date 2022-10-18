#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[100005],l[100005],r[100005],m,x;
ll a1, a2;

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
        if (!l[a[i]]) l[a[i]] = i;
    }
    for (int i = n; i >= 1; --i) {
        if (!r[a[i]]) r[a[i]] = n + 1 - i;
    }
    scanf("%d",&m);
    while (m--) {
        scanf("%d", &x);
        a1 += ll(l[x]);
        a2 += ll(r[x]);
    }

    cout << a1 << " " << a2;

    return 0;
}