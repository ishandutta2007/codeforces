#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=300005;typedef long long ll;const ll inf=1e18;
int a[N],Log2[N];ll s[N];
struct rmq{
	ll f[N][20];
	void init(const std::vector<ll> &a){int n=a.size();for(int i=n;i>=1;--i){f[i][0]=a[i-1];for(int j=1;j<20&&i+(1<<(j-1))<=n;++j)f[i][j]=std::min(f[i][j-1],f[i+(1<<(j-1))][j-1]);}}
	inline ll ask(int l,int r){int k=Log2[r-l+1];return std::min(f[l][k],f[r-(1<<k)+1][k]);}
}f,g;
struct qry{ll v;int opt;};
std::vector<qry> Q[N];
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+(i&1?-a[i]:a[i]);
	std::vector<ll> F,G;
	for(int i=1;i<=n+1;++i)F.pb(i%2?-s[i]:inf),G.pb(i%2?inf:s[i]);
	f.init(F),g.init(G);
	for(int i=0;i<=n+2;++i)Q[i].clear();
	for(int i=0;i<n;++i){
		int l=i+1,r=n,mid;
		while(l<r)mid=(l+r+1)>>1,(f.ask(i+1,mid)+s[i]>=0)&&(g.ask(i+1,mid)-s[i]>=0)?l=mid:r=mid-1;
		Q[i+1].pb({s[i],1}),Q[l+1].pb({s[i],-1});
	}
	std::map<ll,int> mp;ll ans=0;
	for(int i=n;i>=0;--i){
		++mp[s[i]];
		for(const auto &it:Q[i])ans+=it.opt*mp[it.v];
	}
	printf("%lld\n",ans);
}
int main(){
	for(int i=2;i<N;++i)Log2[i]=Log2[i>>1]+1;
	int _;read(_);
	while(_--)MAIN();
	return 0;
}