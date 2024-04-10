#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
int n,minn,cnt,rx,ry;
bool tag[1001],leaf[1001];
bitset<1001> v[1001],g[1001],vis;
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
int main()
{
    n=read();
    if(n==1)
        return 0;
    if(n==2)
    {
        cout<<"1 2\n";
        return 0;
    }
    minn=n;
    for(int i=1;i<=n;++i)
    {
        int p=read();
        minn=min(minn,p);
        while(p--)
            v[i][read()]=1;
    }
    if(minn==n)
    {
        for(int i=2;i<=n;++i)
            cout<<"1 "<<i<<'\n';
        return 0;
    }
    for(int i=1;i<=n;++i)
        leaf[i]=1;
    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j)
        {
            bitset<1001> tmp=v[i]&v[j];
            if(tmp.count()==2)
            {
                int x=tmp._Find_first(),y=tmp._Find_next(x);
                if(!g[x][y])
                {
                    ++cnt;
                    cout<<x<<" "<<y<<'\n';
                    rx=x;
                    ry=y;
                    leaf[x]=leaf[y]=0;
                    g[x][y]=g[y][x]=1;
                }
            }
        }
    if(cnt==1)
    {
        for(int i=1;i<=n;++i)
            if(v[i].count()<n)
            {
                for(int j=1;j<=n;++j)
                    if(leaf[j])
                        cout<<j<<" "<<(v[i][j]? rx:ry)<<'\n';
                break;
            }
        return 0;
    }
    for(int i=1;i<=n;++i)
        if(!leaf[i])
            g[i][i]=tag[i]=vis[i]=1;
    for(int i=1;i<=n;++i)
        if(!tag[i])
        {
            bitset<1001> tmp,res;
            tmp.set();
            //tmp=~tmp;
            for(int j=1;j<=n;++j)
                if(v[j][i]&&v[j].count()<tmp.count())
                    tmp=v[j];
            res=tmp&vis;
            for(int j=1;j<=n;++j)
                if(res==g[j])
                    for(int k=1;k<=n;++k)
                        if(tmp[k]&&!vis[k])
                        {
                            tag[k]=1;
                            cout<<j<<" "<<k<<'\n';
                        }
        }
    return 0;
}