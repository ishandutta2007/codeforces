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

int arr[100020];

void Main(){
	int n, q;
	cin >> n >> q;
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		cnt += arr[i];
	}
	while (q--){
		int m;
		cin >> m;
		if (m == 1){
			int x;
			cin >> x;
			if (arr[x] == 1){ cnt -= 1; }
			else{ cnt += 1; }
			arr[x] ^= 1;
		}
		if (m == 2){
			int k;
			cin >> k;
			cout << (cnt >= k) << endl;
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