#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pr;
const int mod=1e9+7;
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
char a[45];
int m,n,f[45],ff[45],jc[45],ny[45],f1[45];
int C(int x,int y){
	if(x<y||x<0||y<0)return 0;
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
}
void upd(int &x,int y){
	x+=y,(x>=mod&&(x-=mod));
}
int Getans(int c0,int c1){
	int ans=0;
	for(int i=0;i<=c1;i++){// i ?1 ?0
		ans=(ans+1ll*(i%2?mod-1:1)*C(c1,i)%mod*f[i+c0]%mod*jc[i+c0])%mod;
	}
	return ans;
}
const int M=20045161,N=10000000;
pair<ll,int> stats[N+5];
int ac=0;
struct Hash{
 
int h[M+5],v[N+5],cl[N+5],tot,nxt[N+5];
ll fr[N+5];
void A(ll x,int y){
	if(!y)return ;
	int p=x%M;
	for(int i=h[p];i;i=nxt[i])if(fr[i]==x)return upd(v[i],y);
	if(!h[p])cl[++cl[0]]=p;
	++tot,v[tot]=y,nxt[tot]=h[p],h[p]=tot,fr[tot]=x;assert(tot<=N);
}
void Getall(){
	while(cl[0]){
		int p=cl[cl[0]];
		for(int i=h[p];i;i=nxt[i])stats[++ac]=pr(fr[i],v[i]);
		h[p]=0;
		cl[0]--;
	}
	tot=0;
}
 
}hsh;
pr pq[2000005];
ll aaa[45],aa;
int main(){
	scanf("%s%d",a,&n),m=strlen(a),f[0]=jc[0]=ny[0]=1;
	for(int i=1;i<=m;i++)jc[i]=1ll*jc[i-1]*i%mod,ny[i]=Power(jc[i],mod-2);
	int prod=1,c0=0,ans=0;
	hsh.A(0,1);
	ll a1=0;
	for(int i=0;i<m;i++)if(a[i]=='1')a1|=(1ll<<i);else c0++;
	for(int i=1;i<=n;i++)scanf("%lld%d",&pq[i].first,&pq[i].second);
	sort(pq+1,pq+n+1);
	for(int i=1;i<=n;i++){
		ll p=pq[i].first,q=pq[i].second;
		prod=1ll*prod*Power(p,q-1)%mod;
		if(p>=m){
			for(int j=0;j<=m;j++){
				ff[j]=(ff[j]+1ll*f[j]*(p-j))%mod;//
				upd(ff[j+1],f[j]);//
			}
			memcpy(f,ff,sizeof(f)),memset(ff,0,sizeof(ff));
		}
		else {
			ll M=0;
			int c1=0;
			aa=0;
			for(int j=0;j<p;j++){
				ll sta=0;
				for(int k=j;k<m;k+=p)sta|=(1ll<<k);
				if((sta&a1))continue;
				if(__builtin_popcountll(sta)==1){
					c1++,M|=sta;
					continue;
				}
				aaa[++aa]=sta;
			}
			ll M2=0;
			int nxt=pq[i+1].first;
			if(i==n)nxt=1e9;
			for(int j=0;j<m;j++){
				if(j<nxt&&j+nxt>=m){
					M2|=(1ll<<j);
				}
			}
			hsh.Getall();
			for(int k=1;k<=ac;k++){
				ll s=stats[k].first;
				int cnt1mid=__builtin_popcountll(s&M)+(s>>m);
				s=(s&((1ll<<m)-1)&(~M));
				for(int p=1;p<=aa;p++){
					ll ns=(s|aaa[p]);
					ll nns=(ns&(~M2)),mid1=cnt1mid+__builtin_popcountll(ns-nns);
					hsh.A(nns|((1ll<<m)*mid1),stats[k].second);
				}
				//c1
				//cnt1mid 
				ll ns=(s&(~M2)),mid1=cnt1mid+__builtin_popcountll(s-ns)+1;
				hsh.A(ns|((1ll<<m)*mid1),1ll*stats[k].second*(c1-cnt1mid)%mod);
				mid1--;
				hsh.A(ns|((1ll<<m)*mid1),1ll*stats[k].second*cnt1mid%mod);
			}
			ac=0;
		}
	}
	hsh.Getall();
	for(int k=1;k<=ac;k++)
		upd(f1[__builtin_popcountll(stats[k].first&((1ll<<m)-1))+(stats[k].first>>m)],stats[k].second);
	for(int i=0;i<=c0;i++)upd(ans,1ll*f1[i]*Getans(c0-i,m-c0)%mod);
	cout<<1ll*ans*prod%mod<<'\n';
}