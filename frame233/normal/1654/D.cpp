#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=200005,mod=998244353;typedef long long ll;typedef std::pair<int,int> pi;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
bool pr[N];int p[N],pos,inv[N];
std::vector<pi> d[N];
void sieve(){
	for(int i=2;i<N;++i){
		if(!pr[i])p[++pos]=i,d[i]={{i,1}};
		for(int j=1;j<=pos&&i*p[j]<N;++j){
			pr[i*p[j]]=1,d[i*p[j]]=d[i];
			if(i%p[j]==0){++d[i*p[j]].back().second;break;}
			d[i*p[j]].pb({p[j],1});
		}
	}
}
struct edge{int v,x,y;};
std::vector<edge> e[N];
int LCM[N],GCD[N],a[N];
void dfs1(int x,int fa){
	for(const auto &it:e[x]){
		int v=it.v,p=it.x,q=it.y;if(v==fa)continue;
		for(const auto &it:d[p])a[it.first]+=it.second;
		for(const auto &it:d[q])a[it.first]-=it.second,chmin(GCD[it.first],a[it.first]);
		dfs1(v,x);
		for(const auto &it:d[p])a[it.first]-=it.second;
		for(const auto &it:d[q])a[it.first]+=it.second;
	}
}
int ans;
void dfs2(int x,int fa,int val){
	add(ans,val);
	for(const auto &it:e[x]){
		int v=it.v,p=it.x,q=it.y;
		if(v!=fa)dfs2(v,x,1LL*val*p%mod*ksm(q)%mod);
	}
}
void MAIN(){
	int n;read(n);memset(LCM,0,(n+3)<<2);
	for(int i=1;i<=n;++i)e[i].clear();
	for(int i=1,a,b,x,y;i<n;++i){
		read(a,b,x,y),e[a].pb({b,y,x}),e[b].pb({a,x,y});
		for(const auto &it:d[y])chmax(LCM[it.first],it.second);
	}
	memcpy(a,LCM,(n+3)<<2),memcpy(GCD,LCM,(n+3)<<2),dfs1(1,0);
	int coef=1;for(int i=1;i<=n;++i)coef=1LL*coef*ksm(i,LCM[i]-GCD[i])%mod;
	ans=0,dfs2(1,0,coef);printf("%d\n",ans);
}
int main(){
	inv[0]=inv[1]=1;for(int i=1;i<N;++i)inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	sieve();
	int _;read(_);
	while(_--)MAIN();
	return 0;
}