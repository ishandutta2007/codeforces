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

int n, q, ans;
int a[200010];
int s[200010];
int e[200010];
int cnt[200010];
vector<pair<pii, int> > v;

int main() {
	fast;

	cin >> n >> q;

	for(int i=1; i<=200000; i++) {
		s[i] = inf;
		e[i] = 0;
	}

	for(int i=1; i<=n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		s[a[i]] = min(s[a[i]], i);
		e[a[i]] = max(e[a[i]], i);
	}

	for(int i=1; i<=200000; i++) {
		if(cnt[i]) {
			v.pb({{s[i], e[i]}, cnt[i]});
			//cout << s[i] << " " << e[i] << " " << cnt[i] << endl; 
		}
	}

	sort(all(v));

	for(int i=0; i<v.size(); ) {
		int last = v[i].fi.se;
		int j, mx = -1, sum = 0;
		for(j = i; j<v.size(); j++) {
			if(last < v[j].fi.fi) break;

			last = max(last, v[j].fi.se);
			mx = max(mx, v[j].se);
			sum += v[j].se;
		}

		ans += sum - mx;
		i = j;
	}

	cout << ans;
}