#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int arr[120];

void Main(){
	int t;
	cin >> t;
	while (t--){
		ll n, u, v;
		cin >> n >> u >> v;
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
		}
		bool sam = 1, blo = 1;
		for (int i = 1; i < n; i++){
			sam &= (arr[i] == arr[i+1]);
			blo &= (abs(arr[i] - arr[i+1]) <= 1);
		}
		if (sam){
			cout << v + min(u, v) << endl;
		}
		else if (blo){
			cout << min(u, v) << endl;
		}
		else{
			cout << 0 << endl;
		}
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