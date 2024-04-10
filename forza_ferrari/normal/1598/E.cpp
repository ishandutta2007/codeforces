#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,m,q,ans;
bool mp[1001][1001];
int dx[2],dy[2];
inline int solve(int x,int y)
{
    for(register int i=0;;++i)
    {
        x+=dx[i&1];
        y+=dy[i&1];
        if(x<=0||x>n||y<=0||y>m||mp[x][y])
            return i+1;
    }
}
signed main()
{
    cin>>n>>m>>q;
    for(register int i=1;i<=n;++i)
    {
        if(i<=m)
            ans+=(n-i+1)*(m-i+1)*(i==1? 1:2);
        if(i+1<=m)
            ans+=(n-i+1)*(m-i);
    }
    for(register int i=1;i<=m;++i)
        if(i+1<=n)
            ans+=(m-i+1)*(n-i);
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        mp[x][y]^=1;
        dx[0]=-1;
        dy[0]=0;
        dx[1]=0;
        dy[1]=-1;
        int a=solve(x,y);
        dx[0]=0;
        dy[0]=1;
        dx[1]=1;
        dy[1]=0;
        int b=solve(x,y);
        if(mp[x][y])
            ans-=a*b;
        else
            ans+=a*b;
        dx[0]=0;
        dy[0]=-1;
        dx[1]=-1;
        dy[1]=0;
        a=solve(x,y);
        dx[0]=1;
        dy[0]=0;
        dx[1]=0;
        dy[1]=1;
        b=solve(x,y);
        if(mp[x][y])
            ans-=a*b-1;
        else
            ans+=a*b-1;
        cout<<ans<<endl;
    }
    return 0;
}