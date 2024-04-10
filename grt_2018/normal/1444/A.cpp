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

const ll INF = 1e18;
int t;
ll p, q;

int main() {_
	cin >> t;
	while(t--) {
		cin >> p >> q;
		if(p % q != 0) {
			cout << p << "\n";
			continue;
		}
		vector<pi>d = {};
		for(ll i = 2; i * i <= q; ++i) {
			int cnt = 0;
			while(q % i == 0) {
				cnt++;
				q /= i;
			}
			if(cnt > 0) {
				d.PB({i, cnt});
			}
		}
		if(q > 1) {
			d.PB({q, 1});
		}
		ll m = p;
		ll b = INF;
		for(auto x : d) {
			int cnt = 0;
			while(p % x.ST == 0) {
				p /= x.ST;
				cnt++;
			}
			ll w = 1;
			for(int i = x.ND; i <= cnt; ++i) {
				w *= x.ST;
			}
			b = min(b, w);
		}
		cout << m / b << "\n";
			
	}
	
}