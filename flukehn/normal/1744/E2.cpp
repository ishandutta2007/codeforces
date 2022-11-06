#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
ll G(int b,ll v){
	return b+v-b%v;
}
void solve(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	vector<int> p,q;
	for(int i=1;i*i<=a;++i)if(a%i==0) p.push_back(i),p.push_back(a/i);
	for(int i=1;i*i<=b;++i)if(b%i==0) q.push_back(i),q.push_back(b/i);
	for(int u:p)for(int v:q){
		ll s=1LL*u*v;
		ll t=1LL*a*b/u/v;
		ll x=G(a,s);
		ll y=G(b,t);
		if(x<=c&&y<=d){
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