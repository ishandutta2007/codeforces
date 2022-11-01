#include<bits/stdc++.h>
#define pb push_back
#define ls i<<1
#define rs i<<1|1
typedef long long ll;
using namespace std;
const int N=2E5;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(!(c&16));
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16);
    return a*b; 
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
ll sum[N<<2];int l[N<<2],r[N<<2],nex[N<<2],ma[N<<2],mi[N<<2],s,ans;
void cl(int i,int x){ma[i]=mi[i]=nex[i]=x,sum[i]=x*1ll*(r[i]-l[i]+1);}
void rt(int i){sum[i]=sum[ls]+sum[rs],ma[i]=ma[ls],mi[i]=mi[rs];}
void build(int i,int L,int R)
{
    l[i]=L,r[i]=R;
    if(L==R)sum[i]=ma[i]=mi[i]=read();
    else
    {
        int m=(L+R)>>1;
        build(ls,L,m),build(rs,m+1,R),rt(i);
    }
}
void cha(int i,int R,int x)
{
    if(l[i]>R||mi[i]>=x)return;
    if(r[i]<=R&&ma[i]<x)cl(i,x);
    else
    {
        if(nex[i])cl(ls,nex[i]),cl(rs,nex[i]),nex[i]=0;
        cha(ls,R,x),cha(rs,R,x),rt(i);
    }
}
void getans(int i,int L)
{
	if(r[i]<L||mi[i]>s)return;
    if(l[i]>=L&&sum[i]<=s)s-=sum[i],ans+=r[i]-l[i]+1;
    else
    {
        if(nex[i])cl(ls,nex[i]),cl(rs,nex[i]),nex[i]=0;
        getans(ls,L),getans(rs,L);
    }
}
int main()
{
    int n=read(),x=read();
    build(1,1,n);
    while(x--)
    {
        int k=read(),w=read(),v=read();
        if(k==1)cha(1,w,v);
        else s=v,ans=0,getans(1,w),write(ans),putchar('\n');
    }
    return 0;
}