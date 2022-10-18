#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,m,ans;
char a[101][101];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ans=0;
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=m;++j)
            {
                a[i][j]=getchar();
                while(a[i][j]!='R'&&a[i][j]!='D'&&a[i][j]!='C')
                    a[i][j]=getchar();
            }
        for(register int i=1;i<n;++i)
            ans+=(a[i][m]=='R');
        for(register int i=1;i<m;++i)
            ans+=(a[n][i]=='D');
        printf("%d\n",ans);
    }
    return 0;
}