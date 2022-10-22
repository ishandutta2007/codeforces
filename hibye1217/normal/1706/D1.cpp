#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define mkp make_pair
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
template <typename T> using priority_stack = priority_queue< T, vector<T>, greater<T> >;

int arr[3020];

void Main(){
	int t; cin >> t; while (t--){
		int n, k; cin >> n >> k;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		int ans = 1e9;
		for (int mn = 0; mn <= arr[1]; mn++){
			int res = mn;
			for (int i = 1; i <= n; i++){
				int p = 0;
				if (mn == 0){ p = k; }
				else{ p = min(k, arr[i]/mn); }
				res = max(res, arr[i]/p);
			}
			ans = min(ans, res-mn);
		}
		cout << ans << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}