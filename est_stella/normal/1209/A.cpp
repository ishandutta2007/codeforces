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

int n, ans;
vector<int> v;
bool chk[111];

int main() {
	fast;

	cin >> n;
	for(int i=0; i<n; i++) {
		int t;
		cin >> t;
		v.eb(t);
	}

	sort(all(v));

	for(int i=0; i<n; i++) {
		if(chk[i]) continue;

		ans++;
		for(int j=i; j<n; j++) {
			if(v[j] % v[i] == 0) chk[j] = true;
		}
	}

	cout << ans;
}