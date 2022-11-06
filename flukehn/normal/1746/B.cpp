#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=1e5+11;
int n,k;
int a[N];
int f[N], g[N];
int solve(){
	cin>>n;
	For(i,1,n+1) cin>>a[i];
	f[0]=g[n+1]=0;
	For(i,1,n+1) f[i]=f[i-1]+a[i];
	for(int i=n;i>=1;--i) g[i]=g[i+1]+a[i];
	// [0, i-1] 0
	// [i, n] 1
	int ans=n;
	for(int i=1;i<=n+1;++i) {
		int p=f[i-1];
		int q=(n-i+1)-g[i];
		ans=min(ans,max(p,q));
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