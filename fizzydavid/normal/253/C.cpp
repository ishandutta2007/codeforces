#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,-1,1};
int d[110][100100],t[110],n,sx,sy,ex,ey;
int main()
{
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i+=1)cin>>t[i],t[i]++;
    cin>>sx>>sy>>ex>>ey;
    memset(d,-1,sizeof(d));
    d[sx][sy]=0;
    queue<pair<int,int> >q;
    q.push(make_pair(sx,sy));
    while(!q.empty())
    {
        pair<int,int>u=q.front();q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=u.first+dx[i],ny=min(u.second+dy[i],t[nx]);
            if(nx>0&&ny>0&&nx<=n&&d[nx][ny]<0)
            {
                d[nx][ny]=d[u.first][u.second]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    cout<<d[ex][ey];
    return 0;
}