#include <bits/stdc++.h>
#define maxn 500005
#define ll long long
#define pii std::pair<int,int>
#define mp std::make_pair
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int qpow(int a,int b,int mod){
	if(b==0)return 1;
	ll d=qpow(a,b>>1,mod);d=d*d%mod;
	if(b&1)d=d*a%mod;
	return d;
}
int n,m,u,v,vis[maxn],h1[maxn],h2[maxn],m1,m2,b1,b2,dgr[maxn];
int prime[]={998244353,(int)1e9+7,167772161,1004535809,179137447};
int bases[]={11,13,17,19,23,29};
ll a[maxn];
void solve(){
	
	std::cin>>n>>m;
	m1=prime[rand()%5],m2=prime[rand()%5];
	while(m1==m2)m2=prime[rand()%5];
	b1=bases[rand()%6],b2=bases[rand()%6];
	while(b1==b2)b2=bases[rand()%6];
	for(int i=1;i<=n;++i)std::cin>>a[i];
	for(int i=1;i<=n;++i)h1[i]=h2[i]=dgr[i]=0;
	for(int i=1;i<=m;++i){
		std::cin>>u>>v;
		h1[v]=(h1[v]+qpow(b1,u,m1))%m1;
		h2[v]=(h2[v]+qpow(b2,u,m2))%m2;
		dgr[v]=1;
	}std::map<pii,int>table;
	for(int i=1;i<=n;++i){
		vis[i]=1;
		pii P=mp(h1[i],h2[i]);
		if(table.find(P)!=table.end()){
			a[table[P]]+=a[i];
			vis[i]=0;
		}else table[P]=i;
	}
	ll ans=0;
	for(int i=1;i<=n;++i)
		if(vis[i]&&dgr[i])ans=gcd(ans,a[i]);
	std::cout<<ans<<'\n';
}

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);std::cout.tie(0);
	int t;std::cin>>t;while(t--)solve();
	return 0;
}