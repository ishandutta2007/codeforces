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

ll n, q;
ll a[30][30];

int main() {
	cin >> n;

	for(ll i=3; i<=2*n; i++) {
		for(ll j=max(1LL, i-n); j<=min(n, i-1); j++) {
			a[j][i-j] = (j & 1LL) << i-3;
		}
	}

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cin >> q;

	while(q--) {
		ll k;
		cin >> k;

		int x = 1, y = 1;

		cout << "1 1" << endl;

		for(int i=3; i<=2*n; i++) {
			if(x == n) y++;
			else if(y == n) x++;
			else if((k & (1LL << i-3)) == a[x+1][y]) x++;
			else y++;

			cout << x << " " << y << endl;
		}	
	}
}