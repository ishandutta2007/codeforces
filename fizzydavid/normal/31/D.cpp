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
const int INF=1<<28;
const long long LINF=1ll<<61;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
const int UP=0;
const int DOWN=1;
const int LEFT=2;
const int RIGHT=3;
bool con[111][111][4],vis[111][111];
int n,m,NUM,a[10011];
int dfs(int x,int y)
{
//  cout<<x<<" "<<y<<endl;
    vis[x][y]=1;
    int cnt=1;
    for(int i=0;i<4;i++)
    {
        if(con[x][y][i])continue;
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!vis[nx][ny])cnt+=dfs(nx,ny);
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>NUM;
    int x1,y1,x2,y2;
    while(NUM--)
    {
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2)
        {
            for(int i=y1+1;i<=y2;i++)con[x1][i][DOWN]=1,con[x1+1][i][UP]=1;
        }
        else
        {
            for(int i=x1+1;i<=x2;i++)con[i][y1][RIGHT]=1,con[i][y1+1][LEFT]=1;
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<4;k++)cout<<con[i][j][k];
            cout<<endl;
        }
        cout<<endl;
    }
    */
    int size=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!vis[i][j])a[size++]=dfs(i,j);
        }
    }
    sort(a,a+size);
    for(int i=0;i<size;i++)cout<<a[i]<<" ";
    return 0;
}