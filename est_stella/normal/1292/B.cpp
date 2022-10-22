#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;

ll x0, y0, a1, a2, b1, b2, xs, ys, t;
pll p[111];
int mx;
int ans;

ll dist(pll a, pll b) {
	return abs(a.fi - b.fi) + abs(a.se - b.se);
}

int main() {
	fast;

	cin >> x0 >> y0 >> a1 >> a2 >> b1 >> b2;
	cin >> xs >> ys >> t;

	p[0] = mp(x0, y0);
	
	for(int i=1; i<100; i++) {
		p[i] = mp(p[i-1].fi * a1 + b1, p[i-1].se * a2 + b2);
		mx = i;

		if(dist(p[i], mp(xs, ys)) > t && p[i].fi > xs) break;
	}

	for(int i=0; i<mx; i++) {
		ll T = t - dist(p[i], mp(xs, ys));
		if(T < 0) continue;

		int idx = i;
		int cnt = 0;
		for(int j=i; j>=0; j--) {
			if(dist(p[i], p[j]) > T) {
 				break;
			}

			idx = j;
			cnt = i - j + 1;
		}

		//cout << i << " " << idx << endl;

		T -= dist(p[idx], p[i]);

		if(idx == 0) {
			for(int j=i+1; j<mx; j++) {
				if(dist(p[0], p[j]) > T) break;

				cnt++;
			}
		}

		ans = max(ans, cnt);
	}

	cout << ans;
}