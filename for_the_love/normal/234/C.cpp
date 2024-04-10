#include <cstdio>
int n,i,ans;
int l[200000],r[200000],t[200000];
int main()
{
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        scanf("%d",&n);
        for (i=1;i<=n;i++)
        {
                scanf("%d",&t[i]);
                l[i]=l[i-1];
                if (t[i]>=0) l[i]++;
        }
        for (i=n;i>=1;i--)
        {
                r[i]=r[i+1];
                if (t[i]<=0) r[i]++;
        }
        ans=10000000;
        for (i=2;i<=n;i++)
        {
                if (ans>l[i-1]+r[i]) ans=l[i-1]+r[i];
        }
        printf("%d\n",ans);
}