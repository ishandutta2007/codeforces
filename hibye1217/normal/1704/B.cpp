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

const ll INF = 1e15;
ll arr[200020];

void Main(){
	int t; cin >> t; while (t--){
		int n; ll x; cin >> n >> x; x *= 2;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		int ans = 0; ll mn = arr[1], mx = arr[1];
		for (int i = 1; i <= n; i++){
			mn = min(mn, arr[i]); mx = max(mx, arr[i]);
			if (mx-mn > x){ ans += 1; mn = mx = arr[i]; }
		}
		cout << ans << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}