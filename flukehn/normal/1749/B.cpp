#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=2e5+11;
int a[N],b[N];
int n;
ll solve(){
	cin>>n;
	For(i,0,n) cin>>a[i];
	For(i,0,n) cin>>b[i];
	ll ans=0;
	For(i,0,n) ans=max(ans, (ll)b[i]);
	ans=-ans;
	For(i,0,n) ans+=a[i];
	For(i,0,n) ans+=b[i];
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