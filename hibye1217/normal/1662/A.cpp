#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define ep emplace
#define all(v) (v).begin(), (v).end()
#define rmin(r, x) r = min(r, x)
#define rmax(r, x) r = max(r, x)
#define ends ' '
#define endl '\n'
#define rep(i, s, e) for(int i = s; i <= e; ++i)
#define print(v) copy(all(v), ostream_iterator<int>(cout, " ")), cout << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int mx[20];

int main() {
	fastio;
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){
			int b, d; cin >> b >> d;
			mx[d] = max(mx[d], b);
		}
		bool flg = 1; int sum = 0;
		for (int i = 1; i <= 10; i++){
			if (mx[i] == 0){ flg = 0; }
			sum += mx[i];
		}
		if (!flg){ cout << "MOREPROBLEMS"; } else{ cout << sum; }
		cout << endl;
		for (int i = 1; i <= 10; i++){ mx[i] = 0; }
	}
	return 0;
}