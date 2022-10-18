#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
set<int> s[2000001];
int t,n,m,ans;
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
inline void solve(int x,int y)
{
    while(x<=n)
    {
        int p=x+y;
        if(s[p].empty()||*--s[p].end()<x)
        {
            ++x;
            ++y;
            continue;
        }
        int tmp=*--s[p].end();
        while(!s[p].empty()&&*--s[p].end()>=x)
            s[p].erase(--s[p].end());
        x=tmp;
        y=p-x;
        ++x;
        ++y;
    }
}
int main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                char c=getchar();
                while(c!='0'&&c!='1')
                    c=getchar();
                if(c=='1')
                    s[i+j].emplace(i);
            }
        for(int i=1;i<=n+m;++i)
            if(!s[i].empty())
            {
                ++ans;
                solve(*s[i].begin(),i-*s[i].begin());
            }
        cout<<ans<<'\n';
        ans=0;
        for(int i=1;i<=n+m;++i)
            s[i].clear();
    }
    return 0;
}