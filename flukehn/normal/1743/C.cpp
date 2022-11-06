#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const ll INF=~0uLL>>3;
ll solve(){
	int n;
	string s;
	cin>>n>>s;
	vector<int> a(n);
	For(i,0,n) cin>>a[i];
	ll u[2]={0,-INF};
	for(int i=n-1;i>=0;--i) {
		ll v[2]={0,0};
		if(s[i]=='1') {
			v[0]=max(u[0]+a[i], u[1]+a[i]);
			v[1]=max(u[0], u[1]+a[i]); 
		}else{
			v[0]=max(u[0],u[1]+a[i]);
			v[1]=-INF;
		}
		memcpy(u,v,sizeof(u));
	}
	return max(u[0],u[1]);
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