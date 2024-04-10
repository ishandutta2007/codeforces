#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif

const int N=111;
int n,a[N];
int chk(int k){
	for(int i=k;i<=2*k-1;++i)
		if(a[i]>i-k+1) return 0;
	return 1;
}
int solve(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int k=(n+1)/2;k>=1;--k) {
		if(chk(k)) return k;
	}
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
		cout<<solve()<<"\n";
	}
}