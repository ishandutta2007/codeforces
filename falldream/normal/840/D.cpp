#include<iostream>
#include<cstring>
#define MN 300000
#define N 524288
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,a[MN+5],rt[MN+5],cnt=0;
struct Tree{int l,r,x;}T[MN*20+5];
inline int newnode(int x){T[++cnt]=T[x];return cnt;}

void Modify(int x,int l,int r,int v)
{
    if(++T[x].x,l==r)return;int mid=l+r>>1;
    if(v<=mid) Modify(T[x].l=newnode(T[x].l),l,mid,v);
    else Modify(T[x].r=newnode(T[x].r),mid+1,r,v);
}

int Kth(int x,int nx,int l,int r,int k)
{
    if(l==r) return l;int mid=l+r>>1,Sz=T[T[nx].l].x-T[T[x].l].x;
    if(Sz>=k) return Kth(T[x].l,T[nx].l,l,mid,k);
    else return Kth(T[x].r,T[nx].r,mid+1,r,k-Sz);
}

int Query(int x,int nx,int l,int r,int v)
{
    if(l==r) return T[nx].x-T[x].x;int mid=l+r>>1;
    if(v<=mid) return Query(T[x].l,T[nx].l,l,mid,v);
    else return Query(T[x].r,T[nx].r,mid+1,r,v);
}

int main()
{
    n=read();m=read();
    for(int i=1;i<=n;++i) Modify(rt[i]=newnode(rt[i-1]),1,n,a[i]=read());
    for(int q=1;q<=m;++q)
    {
        int l=read(),r=read(),k=read(),lim=(r-l+1)/k+1,ans=1e9;
        for(int i=lim;i<=r-l+1;i+=lim)
        {
            int x=Kth(rt[l-1],rt[r],1,n,i);
            if(Query(rt[l-1],rt[r],1,n,x)>=lim) ans=min(ans,x);
        }
        printf("%d\n",ans==1e9?-1:ans);
    }
    return 0;
}