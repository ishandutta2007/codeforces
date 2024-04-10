#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
void solve(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	for(ll x=a+1;x<=c;++x){
		ll g=__gcd(1LL*a*b, x);
		ll v=1LL*a*b/g;
		ll y=b+v-b%v;
		if(y<=d){
			cout<<x<<" "<<y<<"\n";
			return;
		}
	}
	cout<<"-1 -1\n";
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}