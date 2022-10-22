#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define ull unsigned long long
#define N 2010
using namespace std;
ll mp[N][N],sx[N][N],sy[N][N];
char s[N];
int n,m;
// int get_x(int x,int y,int k)
// {
//     if(x<=k || y<=k) return -10000000;
//     else return sx[x][y]-sx[x-k-1][y-k-1];
// }
// int get_y(int x,int y,int k)
// {
//     if(x<=k || y+k>m) return -10000000;
//     else return sy[x][y]-sy[x-k-1][y+k+1];
// }
bool check(int x,int y,int k,ll c)
{
    if(mp[x+k][y]!=c) return false;
    if(mp[x-k][y]!=c) return false;
    if(mp[x][y+k]!=c) return false;
    if(mp[x][y-k]!=c) return false;
    if(sx[x+k][y]<=k) return false;
    if(sx[x][y+k]<=k) return false;
    if(sy[x+k][y]<=k) return false;
    if(sy[x][y-k]<=k) return false;
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        for(int j=1;j<=m;j++) mp[i][j]=s[j]-'a'+1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        sx[i][j]=mp[i][j]==mp[i-1][j-1]?sx[i-1][j-1]+1:1;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
        sy[i][j]=mp[i][j]==mp[i-1][j+1]?sy[i-1][j+1]+1:1;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int p=1;
        for(int j=1;j<=m;j++)
        {
            for(;i-p>=1 && i+p<=n && j-p>=1 && j+p<=m && check(i,j,p,mp[i][j]);p++);
            ans+=p;
            p=max(p-1,1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}