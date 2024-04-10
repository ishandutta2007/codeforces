#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int t,n,m,cnt,bin[200005];
bool vis[200005][2];
long long a[200005],b[200005];
int pos[200005][2];
vector<int> v[200005];
queue<int> q;
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
inline int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline void solve(int x)
{
    for(auto i:v[x])
    {
        int id=i<=m? i:i-m;
        if(!vis[id][i>m])
        {
            vis[id][i>m]=1;
            if(vis[id][i<=m])
                q.emplace(id);
        }
    }
}
int main()
{
    t=read();
    while(t--)
    {
        cnt=0;
        n=read()+1,m=read();
        for(int i=2;i<=n;++i)
            a[i]=a[i-1]+read();
        for(int i=2;i<=n;++i)
            b[i]=b[i-1]+read();
        for(int i=1;i<=n+1;++i)
        {
            bin[i]=0;
            v[i].clear();
        }
        for(int i=1;i<=m;++i)
        {
            pos[i][0]=read(),pos[i][1]=read()+1;
            vis[i][0]=vis[i][1]=0;
            v[pos[i][0]].emplace_back(i);
            v[pos[i][1]].emplace_back(i+m);
        }
        while(!q.empty())
            q.pop();
        for(int i=1;i<=n;++i)
            if(a[i]==b[i])
            {
                solve(i);
                bin[i]=anc(i+1);
                ++cnt;
            }
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            for(int i=anc(pos[k][0]);i<=pos[k][1];i=anc(i+1))
            {
                solve(i);
                bin[i]=i+1;
                ++cnt;
            }
        }
        cout<<(cnt>=n? "YES":"NO")<<'\n';
    }
    return 0;
}