//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const int mx[4]={1,-1,0,0};
const int my[4]={0,0,1,-1};
int n,m;
bool vis[55][55];
char a[55][55];
bool dfs(int x,int y,int dx,int dy,int l)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+mx[i],ny=y+my[i];
        if(nx==dx&&ny==dy&&l>=4)return true;
        if(nx<1||ny<1||nx>n||ny>m||vis[nx][ny]||a[x][y]!=a[nx][ny])continue;
        if(dfs(nx,ny,dx,dy,l+1))return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i,j,i,j,1))
        {
            cout<<"Yes";return 0;
        }
    }
    cout<<"No";
    return 0;
}