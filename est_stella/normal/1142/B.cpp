#include<bits/stdc++.h>
using namespace std;

int n, m, q;
int p[200001];
int location[200001];
int a[200001];
int b[200001][20];
int s[200001];
int ans[200001];

int main()
{
    scanf("%d%d%d", &n, &m, &q);

    for(int i=1; i<=n; i++) {
        scanf("%d", &p[i]);
        location[p[i]]=i;
    }

    for(int i=1; i<=m; i++) {
        scanf("%d", &a[i]);

        int l=location[a[i]];

        if(l>1) b[i][0]=s[l-1];
        else b[i][0]=s[n];

        s[l]=i;
    }
    for(int i=1; (1<<i)<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            b[j][i]=b[b[j][i-1]][i-1];
        }
    }

    for(int i=1; i<=m; i++)
    {
        int t=n-1, cnt=0;
        int r=i;

        while(t>0)
        {
            if(t&1) r = b[r][cnt];

            t/=2;
            cnt++;
        }

        ans[i]=max(ans[i-1], r);
    }

    while(q--)
    {
        int l, r, t=n-1, cnt=0;
        scanf("%d%d", &l, &r);

        if(l<=ans[r]) printf("1");
        else printf("0");
    }
}