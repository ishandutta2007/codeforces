#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,cnt[11],node[11],g[11][11],m;
inline bool check()
{
    for(int s=0;s<1<<m;++s)
    {
        int res=0;
        for(int i=1;i<=m;++i)
            if(s>>(i-1)&1)
                res+=cnt[i];
        if(!res)
            continue;
        for(int i=1;i<=m;++i)
            if(s>>(i-1)&1)
                for(int j=1;j<=m;++j)
                    if(s>>(j-1)&1)
                        res-=g[i][j];
        if(res<=0)
            return 0;
    }
    return 1;
}
inline bool solve()
{
    for(int i=1;i<=m;++i)
        for(int j=1;j<=m;++j)
            if(g[i][j])
            {
                if(cnt[i])
                {
                    --cnt[i];
                    --g[i][j];
                    if(check())
                    {
                        cout<<node[i]-cnt[i]<<" "<<node[j]<<'\n';
                        return 1;
                    }
                    ++cnt[i];
                    ++g[i][j];
                }
                if(cnt[j])
                {
                    --cnt[j];
                    --g[i][j];
                    if(check())
                    {
                        cout<<node[i]<<" "<<node[j]-cnt[j]<<'\n';
                        return 1;
                    }
                    ++cnt[j];
                    ++g[i][j];
                }
            }
    return 0;
}
inline int popcnt(int x)
{
    int res=0;
    while(x)
    {
        ++res;
        x/=10;
    }
    return res;
}
int main()
{
    cin>>n;
    m=popcnt(n);
    for(int i=1;i<=n;++i)
    {
        ++cnt[popcnt(i)];
        node[popcnt(i)]=i;
    }
    for(int i=1;i<n;++i)
    {
        string a,b;
        cin>>a>>b;
        ++g[a.length()][b.length()];
    }
    if(!check())
    {
        cout<<"-1\n";
        return 0;
    }
    while(solve());
    return 0;
}