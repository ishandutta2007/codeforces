#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[100001],bin[100001],s[100001];
long long ans;
struct edge
{
    int x,y,w;
    bool operator <(const edge &other) const
    {
        return w>other.w;
    }
}e[100001];
inline int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        s[i]=1;
    }
    for(int i=1;i<=m;++i)
    {
        cin>>e[i].x>>e[i].y;
        e[i].w=min(a[e[i].x],a[e[i].y]);
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=m;++i)
    {
        int x=anc(e[i].x),y=anc(e[i].y);
        if(x^y)
        {
            ans+=1ll*s[x]*s[y]*e[i].w;
            bin[y]=x;
            s[x]+=s[y];
        }
    }
    printf("%.10lf\n",2.0*ans/n/(n-1));
    return 0;
}