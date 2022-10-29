#include <cstdio>
#include <cstring>
int n,na,nb,i,j,ans;
int h[300],s[300];
int f[300][40550][2];
int min(int a,int b)
{
        if (a>b) return b; else return a;
}
int main()
{
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        scanf("%d",&n);
        scanf("%d%d",&na,&nb);
        for (i=1;i<=n;i++)
        {
                scanf("%d",&h[i]);
                s[i]=s[i-1]+h[i];
        }
        memset(f,0x7f,sizeof(f));
        f[0][0][0]=0; f[0][0][1]=0; ans=1000000000;
        for (i=1;i<=n;i++)
        for (j=0;j<=na&&s[i-1]>=j;j++)
        {
                if (j+h[i]<=na&&s[i-1]-j<=nb) f[i][j+h[i]][0]=min(f[i-1][j][0],f[i-1][j][1]+min(h[i],h[i-1]));
                if (s[i]-j<=nb) f[i][j][1]=min(f[i-1][j][1],f[i-1][j][0]+min(h[i],h[i-1]));
                if (i==n)
                {
                        ans=min(ans,min(f[i][j+h[i]][0],f[i][j][1]));
                }
        }
        if (ans<1000000000) printf("%d\n",ans);else printf("%d\n",-1);
        return 0;
}