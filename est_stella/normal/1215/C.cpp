#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0)
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define pre(a) cout<<fixed; cout.precision(a);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INF = 1e18;
const int inf = 1e9;

int n;
string s, t;
vector<int> ab, ba;
vector<pii> ans;

int main() {
	fast;
	cin >> n;
	cin >> s >> t;

	for(int i=0; i<n; i++) {
		if(s[i] == 'a' && t[i] == 'b') ab.pb(i);
		if(s[i] == 'b' && t[i] == 'a') ba.pb(i);
	}

	if((ab.size() + ba.size()) % 2 != 0) {
		cout << -1;
		return 0;
	}

	if(ab.size() % 2 != 0) {
		ans.eb(ab.back(), ab.back());
		ba.pb(ab.back());
		ab.pop_back();
	}

	for(int i=0; i<ab.size(); i+=2) {
		ans.eb(ab[i], ab[i+1]);
	}

	for(int i=0; i<ba.size(); i+=2) {
		ans.eb(ba[i], ba[i+1]);
	}

	cout << ans.size() << "\n";

	for(int i=0; i<ans.size(); i++) {
		cout << ans[i].fi+1 << " " << ans[i].se+1 << "\n";
	}
}