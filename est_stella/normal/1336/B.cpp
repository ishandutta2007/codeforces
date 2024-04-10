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

void solve() {
	int nr, ng, nb;
	ll ans = INF * 9;
	vector<ll> r, g, b;

	cin >> nr >> ng >> nb;

	for(int i=0; i<nr; i++) {
		int x;
		cin >> x;

		r.eb(x);
	}
	for(int i=0; i<ng; i++) {
		int x;
		cin >> x;

		g.eb(x);
	}
	for(int i=0; i<nb; i++) {
		int x;
		cin >> x;

		b.eb(x);
	}

	sort(all(r));
	sort(all(g));
	sort(all(b));

	for(auto ub : r) {
		if(g[0] > ub || b[0] > ub) continue;
		
		ll G = *prev(upper_bound(all(g), ub));
		ll B = *prev(upper_bound(all(b), ub));
		
		ll lb = 0;
		if(G < B) {
			lb = G;

			if(upper_bound(all(b), (lb + ub)/2) != b.begin()) {
				B = *prev(upper_bound(all(b), (lb + ub)/2));
				ans = min(ans, (lb - ub)*(lb - ub) + (lb - B) * (lb - B) + (B - ub) * (B - ub));
			}

			if(lower_bound(all(b), (lb + ub + 1)/2) != b.end()) {
				B = *lower_bound(all(b), (lb + ub + 1)/2);
				ans = min(ans, (lb - ub)*(lb - ub) + (lb - B) * (lb - B) + (B - ub) * (B - ub));
			}
		}
		else {
			lb = B;

			if(upper_bound(all(g), (lb + ub)/2) != g.begin()) {
				G = *prev(upper_bound(all(g), (lb + ub)/2));
				ans = min(ans, (lb - ub)*(lb - ub) + (lb - G) * (lb - G) + (G - ub) * (G - ub));
			}

			if(lower_bound(all(g), (lb + ub + 1)/2) != g.end()) {
				G = *lower_bound(all(g), (lb + ub + 1)/2);
				ans = min(ans, (lb - ub)*(lb - ub) + (lb - G) * (lb - G) + (G - ub) * (G - ub));
			}
		}
	}

	for(auto ub : g) {
		if(r[0] > ub || b[0] > ub) continue;
		
		ll R = *prev(upper_bound(all(r), ub));
		ll B = *prev(upper_bound(all(b), ub));
		
		ll lb = 0;
		if(R < B) {
			lb = R;

			if(upper_bound(all(b), (lb + ub)/2) != b.begin()) {
				B = *prev(upper_bound(all(b), (lb + ub)/2));
				ans = min(ans, (lb - ub)*(lb - ub) + (lb - B) * (lb - B) + (B - ub) * (B - ub));
			}

			if(lower_bound(all(b), (lb + ub + 1)/2) != b.end()) {
				B = *lower_bound(all(b), (lb + ub + 1)/2);
				ans = min(ans, (lb - ub)*(lb - ub) + (lb - B) * (lb - B) + (B - ub) * (B - ub));
			}
		}
		else {
			lb = B;

			if(upper_bound(all(r), (lb + ub)/2) != r.begin()) {
				R = *prev(upper_bound(all(r), (lb + ub)/2));
				ans = min(ans, (lb - ub)*(lb - ub) + (lb - R) * (lb - R) + (R - ub) * (R - ub));
			}

			if(lower_bound(all(r), (lb + ub + 1)/2) != r.end()) {
				R = *lower_bound(all(r), (lb + ub + 1)/2);
				ans = min(ans, (lb - ub)*(lb - ub) + (lb - R) * (lb - R) + (R - ub) * (R - ub));
			}
		}
	}

	for(auto ub : b) {
		if(g[0] > ub || r[0] > ub) continue;
		
		ll G = *prev(upper_bound(all(g), ub));
		ll R = *prev(upper_bound(all(r), ub));
		
		ll lb = 0;
		if(G < R) {
			lb = G;

			if(upper_bound(all(r), (lb + ub)/2) != r.begin()) {
				R = *prev(upper_bound(all(r), (lb + ub)/2));
				ans = min(ans, (lb - ub)*(lb - ub) + (lb - R) * (lb - R) + (R - ub) * (R - ub));
			}

			if(lower_bound(all(r), (lb + ub + 1)/2) != r.end()) {
				R = *lower_bound(all(r), (lb + ub + 1)/2);
				ans = min(ans, (lb - ub)*(lb - ub) + (lb - R) * (lb - R) + (R - ub) * (R - ub));
			}

			//cout << lb << " " << R << " " << ub << "!!!!\n";
		}
		else {
			lb = R;

			if(upper_bound(all(g), (lb + ub)/2) != g.begin()) {
				G = *prev(upper_bound(all(g), (lb + ub)/2));
				ans = min(ans, (lb - ub)*(lb - ub) + (lb - G) * (lb - G) + (G - ub) * (G - ub));
			}

			if(lower_bound(all(g), (lb + ub + 1)/2) != g.end()) {
				G = *lower_bound(all(g), (lb + ub + 1)/2);
				ans = min(ans, (lb - ub)*(lb - ub) + (lb - G) * (lb - G) + (G - ub) * (G - ub));
			}

			//cout << lb << " " << G << " " << ub << "!!!!\n";
		}
	}	

	cout << ans << "\n";
}

int main() {
	fast;

	int t;
	cin >> t;

	while(t--) {
		solve();
	}
}