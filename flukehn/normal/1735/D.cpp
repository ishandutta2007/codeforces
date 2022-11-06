#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
int a[1011][20];
int n,k;
void solve(){
	//cin>>n>>k;
	For(i,0,n)For(j,0,k) cin>>a[i][j];
		
	map<ll,int> f;
	For(i,0,n){
		ll x=0;
		For(j,0,k) x=x*3+a[i][j];
		f[x]=i;
	}
	ll ans=0;
	For(i,0,n) {
		int t=0;
		For(j,0,n) {
			if(i==j) continue;
			ll y=0;
			For(p,0,k) y=y*3+(3-a[i][p]-a[j][p]+3)%3;
			if(f.count(y) && f[y] > j) {
				t+=1;
			//	dbg(i, j, f[y]);
			}
		}
		ans+=1LL*t*(t-1)/2;
	}
	cout<<ans<<'\n';
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	while(cin>>n>>k){
		solve();
	}
}