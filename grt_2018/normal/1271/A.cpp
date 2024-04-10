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

int a,b,c,d,e,f;
ll cost;

int main() {_
	cin>>a>>b>>c>>d>>e>>f;
	for(int d1=0; d1<=d; d1++) {
		ll x = (ll)min(a,d1)*e;
		x+=(ll)min({b,c,d-min(a,d1)})*f;
		cost=max(cost,x);
	}
	cout<<cost;
	
}