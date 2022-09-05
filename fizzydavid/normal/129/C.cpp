//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<deque>
#include<iostream>
#include<iomanip>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std;
typedef long long ll;
const int dx[9]={0,0,-1,1,1,1,-1,-1,0};
const int dy[9]={1,-1,0,0,1,-1,1,-1,0};
char g[9][9];
bool f[10][9][9],vis[10][9][9];
queue<int>q;
int main()
{
//  freopen("statues.in","r",stdin);
//  freopen("statues.out","w",stdout);
    ios::sync_with_stdio(false);
    for(int i=0;i<8;i++)for(int j=0;j<8;j++)cin>>g[i][j];
    for(int i=0;i<8;i++)for(int j=0;j<8;j++)if(g[i][j]=='S')f[0][i][j]=1;
    for(int t=1;t<=8;t++)for(int i=0;i<8;i++)for(int j=0;j<8;j++)f[t][i][j]=f[t-1][i-1][j];
    q.push(7);q.push(0);q.push(0);vis[0][7][0]=1;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        int y=q.front();q.pop();
        int t=q.front();q.pop();
        if(t==8)
        {
            cout<<"WIN"<<endl;
            return 0;
        }
        int nx,ny;
        for(int i=0;i<9;i++)
        {
            nx=x+dx[i],ny=y+dy[i];
            if(nx<0||ny<0||nx>7||ny>7||f[t][nx][ny]||f[t+1][nx][ny]||vis[t+1][nx][ny])continue;
            q.push(nx);q.push(ny);q.push(t+1);
            vis[t+1][nx][ny]=1;
        }
    }
    cout<<"LOSE"<<endl;
    return 0;
}