#include<iostream>
#include<cstdio>
using namespace std;
int t,x,y,len,ans;
bool vis[101][101];
int main()
{
    cin>>t;
    while(t--)
    {
        scanf("%d:%d",&x,&y);
        cin>>len;
        ans=0;
        for(int i=0;i<24;++i)
            for(int j=0;j<60;++j)
                vis[i][j]=0;
        while(!vis[x][y])
        {
            vis[x][y]=1;
            ans+=(x%10*10+x/10)==y;
            y+=len;
            x+=y/60;
            y%=60;
            x%=24;
        }
        cout<<ans<<'\n';
    }
    return 0;
}