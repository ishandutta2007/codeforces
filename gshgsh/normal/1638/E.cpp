#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define MAXN 1000001
int N,M;ll c[MAXN],sum[MAXN];
struct ODT{int l,r;mutable int v;ll s;ODT(){}ODT(int x,int y,int z,ll w){l=x,r=y,v=z,s=w;}bool operator<(const ODT&x)const{return l<x.l;}};set<ODT>odt;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
char getc(){char c=getchar();while(c<'A'||c>'Z')c=getchar();return c;}
auto split(int x){if(x>N)return odt.end();auto y=--odt.upper_bound(ODT(x,0,0,0));if((*y).l==x)return y;int l=(*y).l,r=(*y).r,v=(*y).v;ll s=(*y).s;odt.erase(y);odt.insert(ODT(l,x-1,v,s));return odt.insert(ODT(x,r,v,s)).first;}
void Upd(int x,ll v){for(int i=x;i<=N;i+=lowbit(i))c[i]+=v;}
ll Ask(int x){ll ans=0;for(int i=x;i;i-=lowbit(i))ans+=c[i];return ans;}
void assign(int l,int r,int c){auto y=split(r+1),x=split(l);auto tmp=x;while(x!=y)Upd((*x).l,sum[(*x).v]-(*x).s),Upd((*x).r+1,(*x).s-sum[(*x).v]),x++;odt.erase(tmp,y);odt.insert(ODT(l,r,c,sum[c]));}
ll ask(int x){auto b=split(x+1),a=split(x);return sum[(*a).v]-(*a).s+Ask(x);}
int main()
{
	N=get(),M=get();odt.insert(ODT(1,N,1,0));
	For(i,1,M)
	{
		char c=getc();
		if(c=='C'){int l=get(),r=get(),c=get();assign(l,r,c);}
		else if(c=='A'){int x=get();sum[x]+=get();}
		else cout<<ask(get())<<'\n';
	}
	return 0;
}