#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=2e5+11;
ll f(int x,int k) {
	++k;
	if(k>=x) return x;
	int p=x/k;
	int q=x%k;
	return 1LL*p*p*(k-q)+1LL*(p+1)*(p+1)*q;
}
int n,a[N];
using pa=pair<ll,ll>;
pa calc(ll w){// f(x,k) - f(x,k+1) >= m --> choose 
	ll used=0, ans=0;
	for(int i=1;i<=n;++i) {
		int x=a[i];
		int l=0,r=a[i];
		while(l<r){
			int m=(l+r)/2;
			if(f(x,m)-f(x,m+1) >= w) l=m+1;
			else r=m;
		}
		used+=l;
		ans+=f(x, l);
	}
	return pa(used, ans);
}
int solve(){
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=n;i>=2;--i) a[i]-=a[i-1];
	ll K;
	cin>>K;
	ll l=0,r=1.1e18;
	while(l<r){
		ll mid=(l+r+1)/2;
		auto [p, w]=calc(mid);
		if(w<=K) l=mid;
		else r=mid-1;
		//dbg(mid, p, w);
	}
	auto [p, w]=calc(l);
	//dbg(l,p,w);
	p -= (K-w) / (l);
	return p;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	cin.tie(0)->sync_with_stdio(0);
	while(cin>>n){
		cout<<solve()<<"\n";
	}
}