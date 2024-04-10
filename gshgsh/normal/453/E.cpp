#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define R (l+r>>1)
#define L (l+r>>1)+1
#define INF 1000000001
#define MAXN 100001
#define MAXM 10000001
int N,M,s[MAXN],k[MAXN],lim[MAXN],tot,rt[MAXN],ls[MAXM],rs[MAXM];ll sum1[MAXM],sum2[MAXM];
struct ODT{int l,r;mutable int v;ODT(){}ODT(int x,int y,int z){l=x,r=y,v=z;}bool operator<(const ODT&x)const{return l<x.l;}};set<ODT>odt;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
auto split(int x){if(x>N)return odt.end();auto y=--odt.upper_bound(ODT(x,0,0));if((*y).l==x)return y;int l=(*y).l,r=(*y).r,v=(*y).v;odt.erase(y);odt.insert(ODT(l,x-1,v));return odt.insert(ODT(x,r,v)).first;}
int New(int x){tot++;ls[tot]=ls[x],rs[tot]=rs[x],sum1[tot]=sum1[x],sum2[tot]=sum2[x];return tot;}
int upd(int k,int l,int r,int x,int v1,int v2){int u=New(k);l!=r&&(x<=R?ls[u]=upd(ls[u],l,R,x,v1,v2):rs[u]=upd(rs[u],L,r,x,v1,v2));sum1[u]+=v1,sum2[u]+=v2;return u;}
ll ask(ll*sum,int k1,int k2,int l,int r,int x,int y){if(!k1)return 0;if(l>=x&&r<=y)return sum[k1]-sum[k2];ll ans=0;x<=R&&(ans+=ask(sum,ls[k1],ls[k2],l,R,x,y)),y>=L&&(ans+=ask(sum,rs[k1],rs[k2],L,r,x,y));return ans;}
ll ask(int l,int r,int v)
{
	auto y=split(r+1),x=split(l),tmp=x;ll ans=0;
	while(x!=y){if(x->v==-1)ans+=min(1ll*v*k[x->l]+s[x->l],(ll)lim[x->l]);else ans+=ask(sum1,rt[x->r],rt[x->l-1],0,INF,v-x->v,INF)*(v-x->v)+ask(sum2,rt[x->r],rt[x->l-1],0,INF,0,v-x->v-1);x++;}
	odt.erase(tmp,y);odt.insert(ODT(l,r,v));return ans;
}
int main()
{
	N=get();For(i,1,N)s[i]=get(),lim[i]=get(),k[i]=get(),odt.insert(ODT(i,i,-1)),rt[i]=upd(rt[i-1],0,INF,k[i]?lim[i]/k[i]:INF,k[i],lim[i]);M=get();
	For(i,1,M){int t=get(),l=get(),r=get();cout<<ask(l,r,t)<<'\n';}return 0;
}