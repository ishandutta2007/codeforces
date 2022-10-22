#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define pb push_back
#define pre(a) cout<<fixed; cout.precision(a);

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int cnt[500010];

int solve() {
	string s;
	cin >> s;
	ll ans = 0;

	for(int i=0; i<s.size(); i++) {
		int j = i;
		while(j < s.size() && s[j] == '0') {
			j++;
		}
		ll x = j - i;
		ll t = 0;
		ll k = j;
		while(cnt[t] <= x && k < s.size()) {
			t <<= 1;
			t += (s[k++] - '0');
			if(cnt[t] > x || t > 200000) break;
			if(x == 0 || t > 2) ans++;
		}

		if(j > i) j--;
		i = j;
	}

	cout << ans << "\n";
}

int main() {
	fast;

	int t;
	cin >> t;

	int x = 1;
	for(int i=1; i<=200000; i++) {
		cnt[i] = cnt[i-1]+1;
		if(i == x) {
			cnt[i]--;
			x <<= 1;
		}
	}

	while(t--) {
		solve();
	}
}