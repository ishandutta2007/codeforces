#include<bits/stdc++.h>

#define ll long long

using namespace std;
int main() {
	ll t; cin>>t; for(ll i=1; i<=t; i++) {
		ll n, x, y, minx=-100000, maxx=100000, miny=-100000, maxy=100000; bool r, l, u, d;
		cin>>n; for(ll j=1; j<=n; j++) {
			cin>>x>>y>>l>>u>>r>>d;
			if(l==0) minx=max(minx, x);
			if(r==0) maxx=min(maxx, x);
			if(u==0) maxy=min(maxy, y);
			if(d==0) miny=max(miny, y);
		}
		if(minx<=maxx&&miny<=maxy) cout<<1<<" "<<minx<<" "<<miny<<endl;
		else cout<<"0\n";
	}
	return 0;
}