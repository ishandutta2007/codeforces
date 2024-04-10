#include<bits/stdc++.h>
using namespace std;
#define MN 100000
#define ll long long
#define pa pair<int,int>
#define F first
#define S second
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
int X,n,m,a[MN+5];
struct data
{
    int ln,rn,x,L,R;ll ans;
    pa l[22],r[22];
    data(){ln=rn=x=0;ans=0;}
    data(int pos,int val){L=R=l[1].S=r[1].S=pos;ans=(val<X);ln=rn=1;l[1].F=r[1].F=x=val;}
    friend data operator + (const data&a,const data&b)
    {
        data c;c.ans=a.ans+b.ans;c.x=a.x|b.x;c.L=a.L;c.R=b.R;
        memcpy(c.l,a.l,sizeof(pa)*(a.ln+1));c.ln=a.ln;
        memcpy(c.r,b.r,sizeof(pa)*(b.rn+1));c.rn=b.rn;
        for(int i=a.rn,j=0;i;--i) 
        {
            while(j<b.ln&&(a.r[i].F|b.l[j+1].F)<X) ++j;
            c.ans+=1LL*(a.r[i].S-(i<a.rn?a.r[i+1].S:a.L-1))*((j<b.ln?b.l[j+1].S:b.R+1)-b.L);
        }
        for(int i=1;i<=b.ln;++i)
            if((b.l[i].F|a.x)!=c.l[c.ln].F) c.l[++c.ln]=b.l[i],c.l[c.ln].F|=a.x;
        for(int i=1;i<=a.rn;++i) 
            if((a.r[i].F|b.x)!=c.r[c.rn].F) c.r[++c.rn]=a.r[i],c.r[c.rn].F|=b.x;
        return c;
    }
};
struct{int l,r;data x;}T[MN*4+5];
void Build(int x,int l,int r)
{
    if((T[x].l=l)==(T[x].r=r)){T[x].x=data(l,a[l]);return;}
    int mid=l+r>>1;
    Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
    T[x].x=T[x<<1].x+T[x<<1|1].x;
}
void Modify(int x,int k,int v)
{
    if(T[x].l==T[x].r) return (void)(T[x].x=data(k,v));
    int mid=T[x].l+T[x].r>>1;
    Modify(x<<1|(k>mid),k,v);
    T[x].x=T[x<<1].x+T[x<<1|1].x;
}
data Query(int x,int l,int r)
{
    if(T[x].l==l&&T[x].r==r) return T[x].x;
    int mid=T[x].l+T[x].r>>1;
    if(r<=mid) return Query(x<<1,l,r);
    else if(l>mid) return Query(x<<1|1,l,r);
    else return Query(x<<1,l,mid)+Query(x<<1|1,mid+1,r);
}
int main()
{
    n=read();m=read();X=read();
    for(int i=1;i<=n;++i) a[i]=read();
    Build(1,1,n);
    for(int i=1;i<=m;++i)
    {
        int o=read(),x=read(),y=read();
        if(o==1) Modify(1,x,y);
        else printf("%I64d\n",1LL*(y-x+1)*(y-x+2)/2-Query(1,x,y).ans);
    }
    return 0;
}