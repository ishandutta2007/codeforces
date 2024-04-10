#include<iostream>
#include<cstdio>
#include<vector>
#define MN 100000
using namespace std;
inline int read()
{
    int x = 0 , f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}
vector<int> v[MN+5];
int n,k,num[MN+5],rt[MN+5],cnt=0,last=0,a[MN+5];
struct Tree{int l,r,x;}T[5000000];

void Modify(int x,int nx,int k)
{
    int l=1,r=n,mid;T[nx].x=T[x].x+1;
    while(l<r)
    {
        mid=l+r>>1;
        if(k<=mid)T[nx].r=T[x].r,T[nx].l=++cnt,x=T[x].l,nx=T[nx].l,r=mid;
        else T[nx].l=T[x].l,T[nx].r=++cnt,x=T[x].r,nx=T[nx].r,l=mid+1;
        T[nx].x=T[x].x+1;
    }
}

int Query(int x,int k)
{
    int sum=0,l=1,r=n,mid;
    while(l<r)
    {
        mid=l+r>>1;
        if(k<=mid) sum+=T[T[x].r].x,x=T[x].l,r=mid;
        else x=T[x].r,l=mid+1;
    }
    return sum+T[x].x;
}

int main()
{
    n=read();k=read();
    for(int i=1;i<=n;++i)
        v[a[i]=read()].push_back(i);
    for(int i=1;i<=n;++i)
        if(++num[a[i]]>k)
            Modify(rt[i-1],rt[i]=++cnt,v[a[i]][num[a[i]]-k-1]);
        else rt[i]=rt[i-1];
    for(int q=read();q;--q)
    {
        int l=(read()+last)%n+1,r=(read()+last)%n+1;
        if(l>r) swap(l,r);
        printf("%d\n",last=(r-l+1)-Query(rt[r],l));
    }
    return 0;
}