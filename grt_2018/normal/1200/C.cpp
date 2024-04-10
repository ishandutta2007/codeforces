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

const ll INF = (ll)1e18+1;
ll n,m,n2,m2;
int q;


int main() {_
	cin>>n>>m>>q;
	n2=(n/__gcd(n,m));
	m2=(m/__gcd(n,m));
	//cout<<n2<<" "<<m2<<"\n";
	while(q--) {
		int a,b;
		ll c,d;
		cin>>a>>c>>b>>d;
		if(a==1) c=(c-1)/n2+1;
		else c=(c-1)/m2+1;
		if(b==1) d=(d-1)/n2+1;
		else d=(d-1)/m2+1;
		if(c==d) cout<<"YES\n";
		else cout<<"NO\n";
	}
		
}