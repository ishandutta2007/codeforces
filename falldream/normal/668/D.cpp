#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct ques{int k,t,x;}q[MN+5];
struct Tree{int l,r,x;}T[MN*30+5];
int rt[MN+5],cnt=0,L[MN+5],n,TT[MN+5],tot;
inline int newnode(int x){return x?x:++cnt;}
void Modify(int x,int lt,int rt,int k,int ad)
{
    if(T[x].x+=ad,lt==rt)return;
    int mid=lt+rt>>1;
    if(k<=mid) Modify(T[x].l=newnode(T[x].l),lt,mid,k,ad);
    else Modify(T[x].r=newnode(T[x].r),mid+1,rt,k,ad);
}
int Query(int x,int lt,int rt,int l,int r)
{
    if(!x) return 0;
    if(l==lt&&r==rt) return T[x].x;
    int mid=lt+rt>>1;
    if(r<=mid) return Query(T[x].l,lt,mid,l,r);
    else if(l>mid) return Query(T[x].r,mid+1,rt,l,r);
    else return Query(T[x].l,lt,mid,l,mid)+Query(T[x].r,mid+1,rt,mid+1,r);
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) q[i].k=read(),TT[i]=q[i].t=read(),L[i]=q[i].x=read();
    sort(TT+1,TT+n+1);sort(L+1,L+n+1);tot=unique(L+1,L+n+1)-L-1;
    for(int i=1;i<=tot;++i) rt[i]=++cnt;
    for(int i=1;i<=n;++i)
    {
        int t=lower_bound(TT+1,TT+n+1,q[i].t)-TT;
        int x=lower_bound(L+1,L+tot+1,q[i].x)-L;
        if(q[i].k==3) printf("%d\n",L[x]!=q[i].x?0:Query(rt[x],1,n,1,t));
        else Modify(rt[x],1,n,t,q[i].k==1?1:-1);
    }
    return 0;
}