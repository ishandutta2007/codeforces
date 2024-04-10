#include<bits/stdc++.h>
using namespace std;
#define N 300030
const int mod=998244353;
typedef long long ll;
int n,fac[N],cnt1[N],cnt2[N];
map<pair<int,int>,int> mp;
pair<int,int> a[N];
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
}
void Solve(){
	cin>>n;
	init(n);
	int ans=fac[n],A=1,B=1,C=1;
	for(int i=1,x,y;i<=n;++i){
		cin>>x>>y;
		++cnt1[x],++cnt2[y];
		a[i]=make_pair(x,y);
		++mp[make_pair(x,y)];
	}
	for(int i=1;i<=n;++i){
		A=1LL*A*fac[cnt1[i]]%mod;
		B=1LL*B*fac[cnt2[i]]%mod;
	}
	for(auto [x,t]:mp){
		C=1LL*C*fac[t]%mod;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i){
		if(a[i].second>a[i+1].second){C=0;break;}
	}
	ans=(ans-A-B+C)%mod;
	ans=(ans+mod)%mod;
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int T=1;
	while(T--)Solve();
	return 0;
}