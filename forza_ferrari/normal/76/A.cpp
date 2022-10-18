#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
#define int long long
struct edge
{
    int x,y,a,b;
    bool operator <(const edge &other) const
    {
        return a<other.a;
    }
}e[50001];
int n,m,f,g,bin[201],ans;
struct element
{
    int x,y,w;
    bool operator <(const element &other) const
    {
        return w<other.w;
    }
};
multiset<element> s;
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
inline void link(int x,int y)
{
    x=anc(x);
    y=anc(y);
    if(x^y)
        bin[y]=x;
}
inline int kruskal()
{
    int res=0,cnt=0;
    for(int i=1;i<=n;++i)
        bin[i]=0;
    for(auto it=s.begin();it!=s.end();)
        if(anc(it->x)^anc(it->y))
        {
            res=it->w;
            ++cnt;
            link(it->x,it->y);
            ++it;
            if(cnt==n-1)
                break;
        }
        else
            it=s.erase(it);
    return cnt<n-1? 4e18:g*res;
}
signed main()
{
    n=read(),m=read(),f=read(),g=read();
    for(int i=1;i<=m;++i)
        e[i].x=read(),e[i].y=read(),e[i].a=read(),e[i].b=read();
    sort(e+1,e+m+1);
    ans=4e18;
    for(int i=1;i<n-1;++i)
        s.insert({e[i].x,e[i].y,e[i].b});
    for(int i=n-1;i<=m;++i)
    {
        s.insert({e[i].x,e[i].y,e[i].b});
        ans=min(ans,f*e[i].a+kruskal());
    }
    cout<<(ans==4e18? -1:ans)<<'\n';
    return 0;
}