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

int t,a,b,x,y;

int main() {_
	cin >> t;
	while(t--) {
		cin >> x >> y >> a >> b;
		ll ans = 0;
		ans += (ll)abs(x-y) * a;
		if(a * 2 <= b) ans += (ll)min(x,y)*2*a;
		else ans += (ll)min(x,y)*b;
		cout << ans << "\n";
	}
}