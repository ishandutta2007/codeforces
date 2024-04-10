#include<bits/stdc++.h>
using namespace std;

long long n, m;
long long ans;
long long b[100001];
long long g[100001];

int main()
{
    scanf("%lld%lld", &n, &m);

    for(int i=0; i<n; i++)
        scanf("%lld", &b[i]);

    for(int i=0; i<m; i++)
        scanf("%lld", &g[i]);

    sort(b, b+n);
    sort(g, g+m);

    if(b[n-1] > g[0])
    {
        printf("-1");
        return 0;
    }

    for(int i=0; i<n; i++)
    {
        ans += b[i] * m;
    }

    for(int i=0; i<m; i++)
    {
        ans += g[i];
    }

    ans -= b[n-1] * (m-1);
    if(b[n-1] < g[0]) ans -= b[n-2];
    else ans -= b[n-1];

    printf("%lld", ans);
}