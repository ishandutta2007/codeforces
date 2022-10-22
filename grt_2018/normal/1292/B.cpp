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

ll x,y,ax,ay,bx,by;
ll xs,ys,t;
const ll INF = 2*(1e16) + 100;

ll dist(pair<ll,ll>a,pair<ll,ll>b) {
	return llabs(a.ST-b.ST) + llabs(a.ND-b.ND);
}

int main() {_
	cin >> x >> y >> ax >> ay >> bx >> by;
	cin >> xs >> ys >> t;
	vector<pair<ll,ll>> p;
	pair<ll,ll>start = {xs,ys};
	p.emplace_back(x,y);
	while(1) {
		x = x*ax + bx;
		y = y*ay + by;
		if(x > INF || y > INF) break;
		p.emplace_back(x,y);
	}
	int ans = 0;
	//~ cout << (int)p.size() << "\n";
	for(int i = 0; i < (int)p.size(); ++i) {
		ll remain = t;
		pair<ll,ll> last = start;
		//~ cout << i << " " << p[i].ST << " " << p[i].ND << "\n";
		for(int l = i; l >= 0; l--) {
			if(remain >= dist(p[l],last)) {
				remain -= dist(last,p[l]);
			} else {
				break;
			}
			//~ cout << i << " " << remain << " " << l << "\n";
			ans = max(ans,i-l+1);
			ll memo = remain;
			last = p[l];
			for(int r = i+1; r < (int)p.size(); ++r) {
				if(remain >= dist(p[r],last)) {
					remain -= dist(last,p[r]);
				} else {
					break;
				}
				//~ if(i==1) cout << l << " " << r << "\n";
				last = p[r];
				ans = max(ans,r-l+1);
			}
			remain = memo;
			last = p[l];
		}
	}
	cout << ans;
}