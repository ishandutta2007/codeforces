#pragma GCC optimized("Ofast")
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,m,cnt;
vector<int> v[400001];
vector<bool> vis[400001];
vector<pair<int,int> > node;
map<pair<int,int>,bool> mp;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline bool check(int x,int y)
{
    if(v[x][y]==1)
        return 1;
    for(int i=0;i<4;++i)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<=0||xx>n||yy<=0||yy>m)
            continue;
        if(v[xx][yy]<v[x][y])
            return 1;
    }
    return 0;
}
inline bool solve(int l1,int r1,int l2,int r2)
{
    swap(v[l1][r1],v[l2][r2]);
    if(!check(l1,r1)||!check(l2,r2))
    {
        swap(v[l1][r1],v[l2][r2]);
        return 0;
    }
    for(int i=0;i<4;++i)
    {
        int x=l1+dx[i],y=r1+dy[i];
        if(x<=0||x>n||y<=0||y>m)
            continue;
        if(!check(x,y))
        {
            swap(v[l1][r1],v[l2][r2]);
            return 0;
        }
    }
    for(int i=0;i<4;++i)
    {
        int x=l2+dx[i],y=r2+dy[i];
        if(x<=0||x>n||y<=0||y>m)
            continue;
        if(!check(x,y))
        {
            swap(v[l1][r1],v[l2][r2]);
            return 0;
        }
    }
    for(auto i:node)
    {
        if(!check(i.first,i.second))
        {
            swap(v[l1][r1],v[l2][r2]);
            return 0;
        }
        for(int j=0;j<4;++j)
        {
            int x=i.first+dx[j],y=i.second+dy[j];
            if(x<=0||x>n||y<=0||y>m)
                continue;
            if(!check(x,y))
            {
                swap(v[l1][r1],v[l2][r2]);
                return 0;
            }
        }
    }
    swap(v[l1][r1],v[l2][r2]);
    return 1;
}
int main()
{
    n=read(),m=read();
    bool flag=1;
    for(int i=1;i<=n;++i)
    {
        vis[i].resize(m+1);
        v[i].resize(m+1);
        for(int j=1;j<=m;++j)
        {
            v[i][j]=read();
            if(v[i][j]==1)
                node.emplace_back(i,j);
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(!check(i,j))
            {
                flag=0;
                ++cnt;
                node.emplace_back(i,j);
            }
    if(flag)
    {
        cout<<"0\n";
        return 0;
    }
    if(cnt>8)
    {
        cout<<"2\n";
        return 0;
    }
    for(auto p:node)
    {
        if(!vis[p.first][p.second])
        {
            vis[p.first][p.second]=1;
            for(int i=1;i<=n;++i)
                for(int j=1;j<=m;++j)
                    if(i!=p.first||j!=p.second)
                        if(solve(i,j,p.first,p.second))
                            mp[{(i-1)*m+j,(p.first-1)*m+p.second}]=mp[{(p.first-1)*m+p.second,(i-1)*m+j}]=1;
        }
        for(int k=0;k<4;++k)
        {
            int x=p.first+dx[k],y=p.second+dy[k];
            if(x<=0||x>n||y<=0||y>m||vis[x][y])
                continue;
            vis[x][y]=1;
            for(int i=1;i<=n;++i)
                for(int j=1;j<=m;++j)
                    if(i!=x||j!=y)
                        if(solve(i,j,x,y))
                            mp[{(i-1)*m+j,(x-1)*m+y}]=mp[{(x-1)*m+y,(i-1)*m+j}]=1;
        }
    }
    if(mp.size())
        cout<<"1 "<<(mp.size()>>1)<<'\n';
    else
        cout<<"2\n";
    return 0;
}