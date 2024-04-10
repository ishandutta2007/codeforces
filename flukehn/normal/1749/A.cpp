#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif

int solve(){
	int n,m;
	cin>>n>>m;
	vector<int> x(m),y(m);
	For(i,0,m) cin>>x[i]>>y[i];
	if(m>n) return false;
	vector<int> a(n,0), b(n,0);
	For(i,0,m) a[x[i]-1]++,b[y[i]-1]++;
	For(i,0,n) if(a[i]>2 || b[i]>2) return 0;
	int t=0;
	For(i,0,n) t+=(a[i]>1)+(b[i]>1);
	if(n>m) return t<=1;
	return t==1;
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