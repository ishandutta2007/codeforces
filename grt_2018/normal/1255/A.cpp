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

int t,a,b;

int main() {_
	cin>>t;
	while(t--) {
		cin>>a>>b;
		int ans = 0, d = abs(a-b);
		ans+=d/5;
		d=d%5;
		ans+=d/2;
		d%=2;
		if(d==1) ans++;
		cout<<ans<<"\n";
	}
}