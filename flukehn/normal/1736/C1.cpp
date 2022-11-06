#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=2e5+11;
int a[N],n;
int g[N];
ll solve(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	g[1]=a[1];
	for(int i=2;i<=n;++i) g[i]=min(g[i-1], a[i]-i);
	ll ans=0;
	for(int i=1;i<=n;++i){
		//if(a[i]<1-i) continue;
		int l=i,r=n;
		while(l<r){
			int m=(l+r+1)/2;
			dbg(m,g[m],g[m]<=1-i);
			if(g[m]>=1-i) l=m;
			else r=m-1;
		}
		ans+=l-i+1;
		dbg(i, l);
	}
	return ans;
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