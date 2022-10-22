#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int r[120], b[120];
ll sr[120], sb[120];

void Main(){
	int t;
	cin >> t;
	while (t--){
		int n; cin >> n;
		sr[0] = sb[0] = 0;
		for (int i = 1; i <= n; i++){
			cin >> r[i];
			sr[i] = sr[i-1] + r[i];
		}
		int m; cin >> m;
		for (int i = 1; i <= m; i++){
			cin >> b[i];
			sb[i] = sb[i-1] + b[i];
		}
		ll ans = 0;
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= m; j++){
				ans = max(ans, sr[i] + sb[j]);
			}
		}
		cout << ans << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}