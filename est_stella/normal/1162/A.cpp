#include<bits/stdc++.h>
using namespace std;

int n, m, h, ans;
int H[100];

int main()
{
    scanf("%d%d%d", &n, &h, &m);

    for(int i=1; i<=n; i++)
        H[i]=h;

    for(int i=1; i<=m; i++)
    {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);

        for(int i=l; i<=r; i++)
            H[i] = min(H[i], x);
    }

    for(int i=1; i<=n; i++)
    {
        ans += H[i]*H[i];
    }

    printf("%d", ans);
}