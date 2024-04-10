#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

#define ll long long
#define pii pair<ll, ll>

ll m, n, type[100010];
vector<ll> st;
pii val[100010];

ll get(ll a) {
	int i=(int)(lower_bound(st.begin(), st.end(), a)-st.begin());
	if (type[i]==1) {
		return val[i].first;
	} else return get((a-(st[i]-val[i].first*val[i].second+1))%(val[i].first)+1);
}

int main() {
	cin >> m;
	for (ll i=0, len=0; i<m; i++) {
		ll t, l, c;
		cin >> t;
		if (t==1) cin >> val[i].first, len++, st.push_back(len), type[i]=1;
		else {
			cin >> l >> c;
			len+=l*c;
			st.push_back(len);
			val[i].first=l, val[i].second=c;
			type[i]=2;
		}
	}
	cin >> n;
	for (int i=0; i<n; i++) {
		ll a;
		cin >> a;
		cout << get(a) << ' ';
	}
	return 0;
}