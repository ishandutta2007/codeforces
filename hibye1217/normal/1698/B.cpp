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

int arr[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		int ans = 0;
		for (int i = 2; i < n; i++){ ans += (arr[i] > arr[i-1]+arr[i+1]); }
		if (k == 1){ cout << (n-1)/2; } else{ cout << ans; } cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}