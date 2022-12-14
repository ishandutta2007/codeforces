#include<bits/stdc++.h>
#define MN 500000
#define pa pair<int,int>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
struct Tree{int l,r,sum;pa x;}T[MN*5+5];
inline pa operator + (const pa&a,const pa&b){return make_pair(a.first+b.first,min(b.second,a.second+b.first));}
void Build(int x,int l,int r)
{
    if(T[x].x.second=1e9,(T[x].l=l)==(T[x].r=r)) return;
    int mid=l+r>>1;
    Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
}
void Modify(int x,int k)
{
    if(++T[x].sum,T[x].l==T[x].r){++T[x].x.first;T[x].x.second=T[x].l;return;}
    int mid=T[x].l+T[x].r>>1;
    Modify(x<<1|(k>mid),k);
    T[x].x=T[x<<1].x+T[x<<1|1].x;
}
int Get(int x,int pos)
{
    if(T[x].l==T[x].r) return T[x].l;
    int mid=T[x].l+T[x].r>>1;
    if(pos-T[x<<1].sum<=mid) return Get(x<<1,pos);
    else return Get(x<<1|1,pos-T[x<<1].sum);
}
pa Query(int x,int l,int r)
{
    if(T[x].l==l&&T[x].r==r) return T[x].x;
    int mid=T[x].l+T[x].r>>1;
    if(r<=mid) return Query(x<<1,l,r);
    else if(l>mid) return Query(x<<1|1,l,r);
    else return Query(x<<1,l,mid)+Query(x<<1|1,mid+1,r);
}
int main()
{
    n=read();Build(1,0,MN<<1);
    for(int i=1;i<=n;++i)
    {
        int x=read()+MN;Modify(1,x);
        int index=Get(1,MN);
        pair<int,int> res=Query(1,index,MN<<1);
        printf("%d\n",min(res.second,res.first+index)-MN);
    }
    return 0;
}