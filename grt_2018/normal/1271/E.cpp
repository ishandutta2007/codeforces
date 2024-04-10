#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

ll k,n;
ll ans;

int main() {_
	cin>>n>>k;
	ll s = 0, p = 0,r=0;
	while(s+(1LL<<p)<=k) {
		s+=(1LL<<p);
		p++;
	}
	r = k-s-1;
	if(r==-1) {
		p--;
		r=(1LL<<p)-1;
	}
	//cout<<p<<" "<<r<<"\n";
	ll x = (n-r)/(1LL<<p);
	if(x%2==0) x--;
	ans=max(ans,x);
	s=0; p=1; r=0;
	while(s+(1LL<<p)<=k) {
		s+=(1LL<<p);
		p++;
	}
	r = k-s-1;
	if(r==-1) {
		p--;
		r=(1LL<<p)-1;
	}
	x = (n-r)/(1LL<<(p-1));
	if(x%2==1) x--;
	ans=max(ans,x);
	cout<<ans;
	
	
}