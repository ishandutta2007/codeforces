#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef std::pair<int,int> pi;typedef long long ll;typedef __int128 LL;typedef std::pair<ll,ll> pr;
int a[N],b[N],c[N];std::vector<pi> ans;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
inline pr get(int i,int j){
	if(!a[i])return {-c[i],b[i]};
	if(!a[j])return {-c[j],b[j]};
	return {1LL*a[i]*c[j]-1LL*a[j]*c[i],1LL*b[i]*a[j]-1LL*b[j]*a[i]};
}
void dfs(const std::vector<int> &L,int k){
	int n=SZ(L);
	if(n<=k){
		for(auto it:L)ans.pb({it,-1});
		printf("YES\n%d\n",SZ(ans));for(const auto &it:ans)printf("%d %d\n",it.first,it.second);
		exit(0);
	}
	if(!k)return;
	if((double)clock()/CLOCKS_PER_SEC>1.9)puts("NO"),exit(0);
	for(int I=0;I<=k;++I){
		for(int J=I+1;J<=k;++J){
			int i=L[I],j=L[J];if(1LL*a[i]*b[j]==1LL*a[j]*b[i])continue;
			std::vector<int> nl;ll p,q;std::tie(p,q)=get(i,j);
			for(auto k:L)if(k!=i&&k!=j){
				ll P,Q,A,B;std::tie(P,Q)=get(i,k);std::tie(A,B)=get(j,k);
				if((LL)p*Q!=(LL)P*q||(LL)p*B!=(LL)A*q)nl.pb(k);
			}
			ans.pb({i,j}),dfs(nl,k-1),ans.pop_back();
		}
	}
}
int main(){
	int n,k;read(n,k);
	for(int i=1;i<=n;++i)read(a[i],b[i],c[i]);
	std::vector<int> L(n);std::iota(L.begin(),L.end(),1);
	int T=100;
	while(T--&&!L.empty()&&k){
		int i=L[rnd()%SZ(L)],j=L[rnd()%SZ(L)];if(i==j||1LL*a[i]*b[j]==1LL*a[j]*b[i])continue;
		std::vector<int> nl;ll p,q;std::tie(p,q)=get(i,j);int cnt=2;
		for(auto k:L)if(k!=i&&k!=j){
			ll P,Q,A,B;std::tie(P,Q)=get(i,k);std::tie(A,B)=get(j,k);
			if((LL)p*Q!=(LL)P*q||(LL)p*B!=(LL)A*q)nl.pb(k);else ++cnt;
		}
		if(cnt>=k+1)L=nl,ans.pb({i,j}),--k;
	}
	dfs(L,k),puts("NO");
	return 0;
}