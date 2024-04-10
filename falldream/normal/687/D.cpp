#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 1000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,Q,s[MN+5],v[MN+5];
struct edge{int x,y,w,id;}e[MN*MN+5];
bool cmp(const edge&x,const edge&y){return x.w>y.w;}
inline int getfa(int x)
{
    if(!s[x]) return x;
    int f=getfa(s[x]);v[x]^=v[s[x]];
    return s[x]=f;
}
int main()
{
    n=read();m=read();Q=read();
    for(int i=1;i<=m;++i)
    {
        e[i].x=read(),e[i].y=read();
        e[i].w=read(),e[i].id=i;
    }
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=Q;++i)
    {
        int l=read(),r=read(),ans=-1;
        memset(s,0,sizeof(s));memset(v,0,sizeof(v));
        for(int j=1;j<=m;++j) if(e[j].id>=l&&e[j].id<=r)
        {
            int x=getfa(e[j].x),y=getfa(e[j].y);
            if(x!=y) s[x]=y,v[x]=v[e[j].x]^v[e[j].y]^1;
            else if(v[e[j].x]==v[e[j].y]){ans=e[j].w;break;}
        }
        printf("%d\n",ans);
    }
    return 0;
}