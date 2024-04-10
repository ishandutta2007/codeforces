#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=1e9+7;
typedef long long ll;
int n;
class BIT{
	int b[N];
	inline int lowbit(int x){return x&(-x);}
public:
	inline void Add(int x,int d){
		++x;
		while(x<=n)b[x]=(b[x]+d)%mod,x+=lowbit(x);
	}
	int Ask(int x){
		int ans=0;
		while(x)ans=(ans+b[x])%mod,x-=lowbit(x);
		return ans;
	}
}B;
vector<int> a,dp;
vector<int> Get(vector<int> id,int op){
	int n=id.size();
	vector<int> dp(n);
	int sum=0;
	for(int i=n-1;i>=0;--i){
		dp[i]=(sum-B.Ask(a[id[i]]+1)+(op||i==n-1))%mod;
		dp[i]=(dp[i]+mod)%mod;
		B.Add(a[id[i]],dp[i]);
		sum=(sum+dp[i])%mod;
	}
	for(int i=0;i<n;++i){
		B.Add(a[id[i]],mod-dp[i]);
	}
	return dp;
}
void Solve(){
	cin>>n;
	a.clear();
	a.resize(n);
	dp.clear();
	dp.resize(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	auto v=a;
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<n;++i){
		a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();
	}
	auto suf=a;
	for(int i=n-2;i>=0;--i){
		suf[i]=max(suf[i+1],suf[i]);
	}
	vector<int> pos(n);
	for(int i=0;i<n;++i){
		pos[i]=lower_bound(suf.begin(),suf.end(),a[i],greater<int>())-suf.begin()-1;
		pos[i]=max(pos[i],i);
	}
	vector<vector<int> > r(n);
	for(int i=0;i<n;++i){
		r[pos[i]].push_back(i);
	}
	for(int i=0;i<n;++i)dp[i]=0;
	for(int i=0;i<n;++i){
		auto tmp=Get(r[i],0);
		for(int j=0;j<(int)r[i].size();++j){
			dp[r[i][j]]=tmp[j];
		}
	}
	vector<int> id(n);
	iota(id.begin(),id.end(),0);
	auto g=Get(id,1);
	for(int i=0;i<n;++i){
		a[i]=(int)v.size()-1-a[i];
	}
	reverse(id.begin(),id.end());
	auto h=Get(id,1);
	reverse(h.begin(),h.end());
	int ans=0;
	for(int i=0;i<n;++i){
		ans=(ans+1LL*h[i]*(g[i]-dp[i]))%mod;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}