#include<algorithm>
#include<iostream>
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
#define MAXN 101
#define MAXM 400001
int N,M,Q;ll a[MAXN],sb,b[MAXM],da[MAXN],db[MAXM],sum[MAXM],mn[MAXM],tg[MAXM];
ll get(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void build(int k,int l,int r){l!=r?build(ls(k),l,R),build(rs(k),L,r),mn[k]=mn[ls(k)],sum[k]=sum[ls(k)]+sum[rs(k)]:sum[k]=mn[k]=db[l];}
void pt(int k,int l,int r,ll v){sum[k]+=v*(r-l+1),mn[k]+=v,tg[k]+=v;}void dwn(int k,int l,int r){pt(ls(k),l,R,tg[k]),pt(rs(k),L,r,tg[k]),tg[k]=0;}
void upd(int k,int l,int r,int x,int y,ll v){if(l>=x&&r<=y)return pt(k,l,r,v);dwn(k,l,r);x<=R&&(upd(ls(k),l,R,x,y,v),0),y>=L&&(upd(rs(k),L,r,x,y,v),0),mn[k]=mn[ls(k)],sum[k]=sum[ls(k)]+sum[rs(k)];}
pair<ll,int>ask(int k,int l,int r,ll v){if(l==r)return mn[k]<v?make_pair(sum[k],l):make_pair(0ll,0);dwn(k,l,r);if(mn[rs(k)]>=v)return ask(ls(k),l,R,v);auto tmp=ask(rs(k),L,r,v);if(!tmp.second)return {0,0};return {tmp.first+sum[ls(k)],tmp.second};}
int main()
{
	N=get(),M=get(),Q=get();For(i,1,N)a[i]=get();For(i,1,M)sb+=b[i]=get();For(i,1,N-1)da[i]=a[i+1]-a[i];For(i,1,M-1)db[i]=b[i+1]-b[i];build(1,1,M-1);
	For(i,1,Q)
	{
		int type=get(),k=get(),d=get();if(type==1)For(j,N-k+1,N)a[j]+=d*(j-N+k),da[j-1]+=d;else upd(1,1,M-1,M-k,M-1,d),k==M&&(b[1]+=d),sb+=1ll*k*(k+1)/2*d;
		ll sum=a[N]*M+sb;For(j,1,N-1)sum+=a[j]+b[1];For(j,1,N-1){auto x=ask(1,1,M-1,da[j]);sum-=x.second*da[j]-x.first;}cout<<sum<<'\n';
	}
	return 0;
}