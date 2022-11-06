#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=2e5+11;
int s[N];
vector<int> e[N];

map<int,ll> f[N];
int n;
ll F(int x,int k){
	dbg(x,k);
	if(!k) return 0;
	ll ans=1LL*s[x]*k;
	int d=e[x].size();
	if(!d) return ans;
	if(f[x].count(k)) return f[x][k];
	if(k%d==0){
		for(int y:e[x]) ans+=F(y,k/d);
	}else{
		vector<ll> a;
		for(int y:e[x]) {
			ll u=F(y,k/d);
			ll v=F(y,k/d+1);
			ans+=u;
			a.push_back(v-u);
		}
		sort(a.begin(), a.end(), greater<ll>());
		For(i,0,k%d) ans+=a[i];
	}
	dbg(x,k,ans);
	return f[x][k]=ans;
}
ll solve(){
	int k;
	cin>>n>>k;
	for(int i=1;i<=n;++i) e[i].clear();
	for(int i=1;i<=n;++i) f[i].clear();
	for(int i=2;i<=n;++i){
		int p;
		cin>>p;
		e[p].push_back(i);
		dbg(p,i);
	}
	for(int i=1;i<=n;++i)cin>>s[i];
	return F(1,k);
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cout<<solve()<<"\n";
	}
}