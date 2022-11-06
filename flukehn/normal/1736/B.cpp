#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=1e5+11;
int a[N],n;
int solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i+2<=n;++i) {
		int g=__gcd(a[i], a[i+2]);
		if(a[i+1]%g) return 0; 
	}
	return 1;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int r=solve();
		if(r)cout<<"YES\n";
		else cout<<"NO\n";
	}
}