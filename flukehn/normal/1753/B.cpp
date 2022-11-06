#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=5e5+11;
int n,x;
int a[N];
int b[N];
int solve(){
	for(int i=1;i<=n;++i) cin>>a[i];
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;++i) {
		if(a[i]<x)b[a[i]]+=1;
	}
	for(int i=1;i<x;++i) {
		if(b[i] % (i+1)) return 0;
		b[i+1] += b[i]/(i+1);
	}
	return 1;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	while(cin>>n>>x){
		int r=solve();
		if(r) cout<<"Yes\n";
		else cout<<"No\n";
	}
}