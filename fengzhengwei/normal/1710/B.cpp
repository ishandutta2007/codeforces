#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
namespace ppprrr{const int xx=2,mod=2;ll ksm(ll a,ll b){ll ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod,b>>=1;}return ans;}

ll jiec[xx],ni[xx];
ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
void pre()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
}
	
int prim[xx],mn[xx],Cnt;
void pre(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!mn[i])mn[i]=i,prim[++Cnt]=i;
		for(int j=1;j<=Cnt;j++)
		{
			if(prim[j]*i>n)break;
			mn[i*prim[j]]=prim[j];
			if(i%prim[j]==0)break;
		}
	}
}


int lb(int x){return x&-x;}
ll sum[xx];
void Add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}
ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}

struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}


}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
//co 
const int xx=1e6+5,mod=998244353;
//mod1e9+7998 
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
struct pr{int x,y;};
int n,m,k,q,b[xx];
char s[xx];
ll X[xx],P[xx],a[xx];
LL cf[xx],cf_[xx];
//struct nl
//{
//	int x;
//	bool operator<(const nl&w)const{return P[x]+X[x]<w.P[x]+w.X[x];}
//};
//struct nr
//{
//	int x;
//	bool operator<(const nl&w)const{return P[x]-X[x]<w.P[x]-w.X[x];}
//};
//multiset<nl>sl;
//multiset<nr>sr;
int cr[xx];
ll lsh[xx],tt;
int get(ll id){return lower_bound(lsh+1,lsh+tt+1,id)-lsh;}
struct nd
{
	ll sum,jnmn,jamn;
}e[xx<<2];
int ans[xx];
const ll inf=1e18;
nd upd(const nd &a,const nd&b){return {a.sum+b.sum,max(a.jnmn,b.jnmn),max(a.jamn,b.jamn)};}
void build(int k,int l,int r)
{
	if(l==r)
	{
		if(a[l]>m)
		{
			e[k].sum=1;
			//dlt 
			// m  
			e[k].jnmn=(cf_[l]-1)*lsh[l]+cf[l]-m;
			e[k].jamn=(cf_[l]+1)*lsh[l]+cf[l]-m;
//			cerr<<l<<" "<<lsh[l]<<" "<<e[k].jnmn<<" "<<e[k].jamn<<"%%\n";
		}
		else e[k]={0,-inf,-inf};
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	e[k]=upd(e[k<<1],e[k<<1|1]);
}
// 
nd ask(int k,int l,int r,int x,int y)
{
	if(x>y)return {0,-inf,-inf};
	if(x<=l&&r<=y)return e[k];
	int mid=l+r>>1;
	if(y<=mid)return ask(k<<1,l,mid,x,y);
	if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
	return upd(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y));
}
LL dl[xx],dr[xx];
int main(){
	int T=read();
	while(T--)
	{
		tt=0;
		n=read(),m=read();
		for(int i=1;i<=n;i++)X[i]=read(),P[i]=read();
		for(int i=1;i<=n;i++)
			lsh[++tt]=X[i],lsh[++tt]=X[i]-P[i],lsh[++tt]=X[i]+P[i];
		sort(lsh+1,lsh+tt+1);
		// 
		tt=unique(lsh+1,lsh+tt+1)-lsh-1;
		for(int i=1;i<=tt;i++)cf[i]=cf_[i]=a[i]=0;
		for(int i=1;i<=n;i++)
		{
			int L=X[i]-P[i],R=X[i]+P[i],I=X[i];
			int Li=get(L),Ri=get(R),Ii=get(I);
			cf[Li]+=(P[i]-abs(X[i]-L))-L,cf[Ii+1]-=(P[i]-abs(X[i]-L))-L;
			dl[i]=(P[i]-abs(X[i]-L))-L;
			cf_[Li]++,cf_[Ii+1]--;// 
			cf[Ii]+=(P[i]-abs(X[i]-R))-(-R),cf[Ri+1]-=(P[i]-abs(X[i]-R))-(-R);
			dr[i]=(P[i]-abs(X[i]-R))-(-R);
			cf_[Ii]--,cf_[Ri+1]++;// 
			//i 
			// 
			cf[Ii]-=P[i],cf[Ii+1]+=P[i];
		}
		for(int i=1;i<=tt;i++)cf[i]+=cf[i-1];
		for(int i=1;i<=tt;i++)cf_[i]+=cf_[i-1];
		for(int i=1;i<=tt;i++)a[i]=cf[i]+cf_[i]*lsh[i];
//		for(int i=1;i<=tt;i++)
//		{
//			cout<<a[i]<<" "<<lsh[i]<<" "<<(int)cf_[i]<<" "<<(int)cf[i]<<"\n";
//		}
//		puts("SS");
		build(1,1,tt);
		for(int i=1;i<=n;i++)ans[i]=0;
//		for(int i=1;i<=n;i++)cout<<i<<" "<<(int)dl[i]<<" "<<(int)dr[i]<<" "<<"$$\n";
		for(int i=1;i<=n;i++)
		{
			int L=X[i]-P[i],R=X[i]+P[i],I=X[i];
			int Li=get(L),Ri=get(R),Ii=get(I);
			
			if(ask(1,1,tt,1,Li-1).sum)
			{
				ans[i]=0;
				continue;
			}
			if(ask(1,1,tt,Ri+1,tt).sum)
			{
				ans[i]=0;
				continue;
			}
			if(!(dl[i]>=ask(1,1,tt,Li,Ii).jnmn))
			{
				ans[i]=0;
				continue;
			}
			if(!(dr[i]>=ask(1,1,tt,Ii,Ri).jamn))
			{
				ans[i]=0;
				continue;
			}
			ans[i]=1;
		}
		for(int i=1;i<=n;i++)cout<<ans[i];
		puts("");
//		for(int i=1;i<=n;i++)Lid[i]=i,Rid[i]=i;
//		for(int i=1;i<=n;i++)cr[i]=0;
//		sl.clear(),sr.clear();
//		for(int i=1;i<=n;i++)v[i].clear();
//		for(int i=1;i<=n;i++)
//		{
//			v[X[i]].push_back()
//		}
//		for(int i=1;i<=n;i++)
//		{
//			int L=max(1,X[i]-P[i]),R=min(n,X[i]+P[i]);
//			cf[L]+=(P[i]-abs(X[i]-L))-L,cf[i+1]-=(P[i]-abs(X[i]-L))-L;
//			cf_[L]++,cf_[i+1]--;// 
//			cf[i+1]+=(P[i]-abs(X[i]-R))-(-R),cf[R+1]+=(P[i]-abs(X[i]-R))-(-R);
//			cf_[i+1]--,cf_[R+1]++;// 
//		}
//		for(int i=1;i<=n;i++)cf[i]+=cf[i-1];
//		for(int i=1;i<=n;i++)cf_[i]+=cf_[i-1];
//		for(int i=1;i<=n;i++)a[i]=cf[i]+cf_[i]*i;
//		
//		for(int i=1;i<=n;i++)
//		{
//			if(a[i]>m)
//			{
//				
//			}
//		}
	}
	pc('1',1);
	return 0;
}