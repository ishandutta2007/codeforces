#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,bin[200001],s,t,ds,dt,x[400001],y[400001],cnt[3],vis[200001][2];
bool tag;
vector<pair<int,int> > ans;
vector<int> p[3];
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
int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline void link(int x,int y)
{
    ans.push_back(make_pair(x,y));
    x=anc(x);
    y=anc(y);
    if(x^y)
    {
        bin[y]=x;
        if(vis[y][0])
            vis[x][0]=vis[y][0];
        if(vis[y][1])
            vis[x][1]=vis[y][1];
    }
    else
        ans.pop_back();
}
int main()
{
    n=read(),m=read();
    for(register int i=1;i<=m;++i)
        x[i]=read(),y[i]=read();
    s=read(),t=read(),ds=read(),dt=read();
    if(s>t)
    {
        s^=t^=s^=t;
        ds^=dt^=ds^=dt;
    }
    for(register int i=1;i<=m;++i)
    {
        if(x[i]>y[i])
            x[i]^=y[i]^=x[i]^=y[i];
        if(x[i]==s&&y[i]==t)
        {
            tag=1;
            continue;
        }
        if(x[i]==s)
        {
            vis[anc(y[i])][0]=y[i];
            continue;
        }
        if(x[i]==t)
        {
            vis[anc(y[i])][1]=y[i];
            continue;
        }
        if(y[i]==s)
        {
            vis[anc(x[i])][0]=x[i];
            continue;
        }
        if(y[i]==t)
        {
            vis[anc(x[i])][1]=x[i];
            continue;
        }
        link(x[i],y[i]);
    }
    for(register int i=1;i<=n;++i)
        if(anc(i)==i&&i!=s&&i!=t)
        {
            if(vis[i][0]&&vis[i][1])
            {
                ++cnt[2];
                p[2].push_back(i);
                continue;
            }
            if(vis[i][0])
            {
                ++cnt[0];
                p[0].push_back(i);
                continue;
            }
            if(vis[i][1])
            {
                ++cnt[1];
                p[1].push_back(i);
                continue;
            }
            puts("No");
            return 0;
        }
    bool flag=1;
    if(!cnt[2])
        flag=0;
    if(cnt[0]+cnt[1]+cnt[2]+1>ds+dt)
        flag=0;
    if(cnt[0]+1>ds||cnt[1]+1>dt)
        flag=0;
    if(flag)
    {
        puts("Yes");
        printf("%d %d\n",vis[p[2].back()][0],s);
        printf("%d %d\n",vis[p[2].back()][1],t);
        --ds;
        --dt;
        p[2].pop_back();
        for(auto i:ans)
            printf("%d %d\n",i.first,i.second);
        for(auto i:p[0])
        {
            --ds;
            printf("%d %d\n",vis[i][0],s);
        }
        for(auto i:p[1])
        {
            --dt;
            printf("%d %d\n",vis[i][1],t);
        }
        for(auto i:p[2])
        {
            if(ds)
            {
                --ds;
                printf("%d %d\n",vis[i][0],s);
            }
            else
            {
                --dt;
                printf("%d %d\n",vis[i][1],t);
            }
        }
        return 0;
    }
    if(!tag)
    {
        puts("No");
        return 0;
    }
    --ds;
    --dt;
    if(cnt[0]+cnt[1]+cnt[2]>ds+dt)
    {
        puts("No");
        return 0;
    }
    if(cnt[0]>ds||cnt[1]>dt)
    {
        puts("No");
        return 0;
    }
    puts("Yes");
    printf("%d %d\n",s,t);
    for(auto i:ans)
        printf("%d %d\n",i.first,i.second);
    for(auto i:p[0])
    {
        --ds;
        printf("%d %d\n",vis[i][0],s);
    }
    for(auto i:p[1])
    {
        --dt;
        printf("%d %d\n",vis[i][1],t);
    }
    for(auto i:p[2])
        if(ds)
        {
            --ds;
            printf("%d %d\n",vis[i][0],s);
        }
        else
        {
            --dt;
            printf("%d %d\n",vis[i][1],t);
        }
    return 0;
}