//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int n,m;
int con1[22],con2[22];
bool vis[22][22];
void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&ny>0&&nx<=n&&ny<=m&&!vis[nx][ny]&&(dx[i]==0||con2[y]==dx[i])&&(dy[i]==0||con1[x]==dy[i]))dfs(nx,ny);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;cin.ignore();
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        if(c=='>')con1[i]=1;else con1[i]=-1;
    }cin.ignore();
    for(int i=1;i<=m;i++)
    {
        char c;
        cin>>c;
        if(c=='v')con2[i]=1;else con2[i]=-1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            memset(vis,0,sizeof(vis));
            dfs(i,j);
            bool ok=1;
            for(int ii=1;ii<=n;ii++)for(int jj=1;jj<=m;jj++)ok=ok&vis[ii][jj];
            if(ok==0)
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}