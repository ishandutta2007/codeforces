#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 100001
int N,M;ll sum[MAXN*4],tg[MAXN*4];struct ODT{int l,r;mutable int v;ODT(){}ODT(int x,int y,int z){l=x,r=y,v=z;}bool operator<(const ODT&x)const{return l<x.l;}};set<ODT>odt;
void pt(int k,int l,int r,ll v){sum[k]+=v*(r-l+1),tg[k]+=v;}
void dwn(int k,int l,int r){pt(ls(k),l,R,tg[k]),pt(rs(k),L,r,tg[k]),tg[k]=0;}
void upd(int k,int l,int r,int x,int y,int v){if(l>=x&&r<=y)return pt(k,l,r,v);dwn(k,l,r);x<=R&&(upd(ls(k),l,R,x,y,v),0),y>=L&&(upd(rs(k),L,r,x,y,v),0),sum[k]=sum[ls(k)]+sum[rs(k)];}
ll ask(int k,int l,int r,int x,int y){if(l>=x&&r<=y)return sum[k];dwn(k,l,r);ll ans=0;x<=R&&(ans+=ask(ls(k),l,R,x,y)),y>=L&&(ans+=ask(rs(k),L,r,x,y));return ans;}
auto split(int x){if(x>N)return odt.end();auto y=--odt.upper_bound(ODT(x,0,0));if((*y).l==x)return y;int l=(*y).l,r=(*y).r,v=(*y).v;odt.erase(y);odt.insert(ODT(l,x-1,v));return odt.insert(ODT(x,r,v)).first;}
void upd(int l,int r,int v){auto y=split(r+1),x=split(l),tmp=x;while(x!=y)upd(1,1,N,(*x).l,(*x).r,abs((*x).v-v)),x++;odt.erase(tmp,y);odt.insert(ODT(l,r,v));}
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),M=get();For(i,1,N)odt.insert(ODT(i,i,i));
	For(i,1,M){int opt=get(),x=get(),y=get();if(opt==1)upd(x,y,get());else cout<<ask(1,1,N,x,y)<<'\n';}return 0;
}