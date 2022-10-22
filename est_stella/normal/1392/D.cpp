#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define pre(a) cout << fixed; cout.precision(a);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int n;
string s;
vector<int> v;

void solve() {
	v.clear();
	cin >> n;
	cin >> s;

	for(int i=0; i<n; ) {
		int j = i;

		while(j < n && s[i] == s[j]) j++;

		v.eb(j - i);

		i = j;
	}

	if(s[0] == s[n-1] && v.size() > 1) {
		v[0] += v.back();
		v.pop_back();
	}

	int ans = 0;
	if(v.size() == 1) {
		v[0]--;
		ans++;
	}

	for(auto i : v) {
		ans += i / 3;
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