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
int solve(){
	cin>>n>>k;
	For(i,0,n) cin>>a[i];
	For(i,0,n)if(a[i]==1)return 1;
	return 0;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		if(solve()) cout<<"YES\n";
		else cout<<"NO\n";
	}
}