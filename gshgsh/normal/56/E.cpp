#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 100001
int N,x[MAXN],r[MAXN],ans[MAXN],mx[MAXN*4];pair<pair<int,int>,int>a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void upd(int k,int l,int r,int x,int v){l!=r?x<=R?upd(ls(k),l,R,x,v):upd(rs(k),L,r,x,v),mx[k]=max(mx[ls(k)],mx[rs(k)]):mx[k]=v;}
int ask(int k,int l,int r,int x,int y){return l<=y&&r>=x?l<x||r>y?max(ask(ls(k),l,R,x,y),ask(rs(k),L,r,x,y)):mx[k]:0;}
int main()
{
	N=get();For(i,1,N)a[i].first.first=x[i]=get(),a[i].first.second=get(),a[i].second=i;sort(a+1,a+N+1);sort(x+1,x+N+1);
	FOR(i,N,1){int pos=lower_bound(x+1,x+N+1,x[i]+a[i].first.second)-x-1;upd(1,1,N,i,r[i]=max(i,ask(1,1,N,i+1,pos)));ans[a[i].second]=r[i]-i+1;}
	For(i,1,N)cout<<ans[i]<<" \n"[i==N];return 0;
}