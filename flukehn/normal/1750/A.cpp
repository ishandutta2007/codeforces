#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=111;
const int INF=~0u>>2;
int a[N];
int n;
int solve(){
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	int mn=INF;
	for(int i=1;i<=n;++i) {
		for(int j=i+1;j<=n;++j) {
			if(a[i]>a[j]) {
				if(mn>a[j]) return 0;
			}
		}
		mn = min(mn, a[i]);
	}
	return 1;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int r=solve();
		if(r) cout<<"Yes\n";
		else cout<<"No\n";
	}
}