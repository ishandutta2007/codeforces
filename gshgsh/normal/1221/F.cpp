#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 1000001
int N,K,b[MAXN],x[MAXN],y[MAXN],c[MAXN];ll tg[MAXN*4];pair<ll,int>mx[MAXN*4];vector<int>id[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void build(int k,int l,int r){if(l==r){mx[k]={-b[l],l};return;}build(ls(k),l,R);build(rs(k),L,r);mx[k]=max(mx[ls(k)],mx[rs(k)]);}
void pt(int k,ll v){mx[k].first+=v,tg[k]+=v;}void dwn(int k){pt(ls(k),tg[k]),pt(rs(k),tg[k]),tg[k]=0;}
void upd(int k,int l,int r,int x,int y,int v){if(l>=x&&r<=y)return pt(k,v);dwn(k);x<=R&&(upd(ls(k),l,R,x,y,v),0),y>=L&&(upd(rs(k),L,r,x,y,v),0),mx[k]=max(mx[ls(k)],mx[rs(k)]);}
pair<ll,int>ask(int k,int l,int r,int x,int y){if(l>=x&&r<=y)return mx[k];dwn(k);pair<ll,int>ans={-1e18,0};x<=R&&(ans=max(ans,ask(ls(k),l,R,x,y)),0),y>=L&&(ans=max(ans,ask(rs(k),L,r,x,y)),0);return ans;}
int main()
{
	N=get();For(i,1,N)b[++K]=x[i]=get(),b[++K]=y[i]=get(),c[i]=get();sort(b+1,b+K+1);K=unique(b+1,b+K+1)-b-1;For(i,1,N)if(x[i]>y[i])swap(x[i],y[i]);
	For(i,1,N)x[i]=lower_bound(b+1,b+K+1,x[i])-b,y[i]=lower_bound(b+1,b+K+1,y[i])-b,id[x[i]].push_back(i);build(1,1,K);
	ll mx=0,l=2e9,r=2e9;FOR(i,K,1){for(auto j:id[i])upd(1,1,K,y[j],K,c[j]);auto x=ask(1,1,K,i,K);x.first+=b[i];if(x.first>mx)mx=x.first,l=b[i],r=b[x.second];}
	cout<<mx<<'\n'<<l<<' '<<l<<' '<<r<<' '<<r<<'\n';
}