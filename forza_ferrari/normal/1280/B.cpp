#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,sum,ans,x[101],y[101];
char mp[101][101];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        sum=0;
        for(register int i=1;i<=n;++i)
            x[i]=0;
        for(register int i=1;i<=m;++i)
            y[i]=0;
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=m;++j)
            {
                cin>>mp[i][j];
                sum+=mp[i][j]=='A';
                x[i]+=mp[i][j]=='A';
                y[j]+=mp[i][j]=='A';
            }
        if(!sum)
        {
            puts("MORTAL");
            continue;
        }
        if(sum==n*m)
        {
            puts("0");
            continue;
        }
        ans=4;
        if(mp[1][1]=='A'||mp[1][m]=='A'||mp[n][1]=='A'||mp[n][m]=='A')
            ans=2;
        if(x[1]==m||x[n]==m)
            ans=1;
        if(y[1]==n||y[m]==n)
            ans=1;
        for(register int i=1;i<=n;++i)
        {
            if(mp[i][1]=='A')
                ans=min(ans,3);
            if(mp[i][m]=='A')
                ans=min(ans,3);
            if(x[i]==m)
                ans=min(ans,2);
        }
        for(register int i=1;i<=m;++i)
        {
            if(mp[1][i]=='A')
                ans=min(ans,3);
            if(mp[n][i]=='A')
                ans=min(ans,3);
            if(y[i]==n)
                ans=min(ans,2);
        }
        printf("%d\n",ans);
    }
    return 0;
}