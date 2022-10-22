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

ll arr[5020];
ll lazy[5020];

void Main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
			lazy[i] = 0;
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++){
			while (lazy[i] > 0){
				if (arr[i] == 1){
					lazy[i+1] += lazy[i];
					lazy[i] = 0;
				}
				else{
					int p = i + arr[i];
					if (p <= n){ lazy[p] += 1; }
					lazy[i] -= 1;
					if (arr[i] > 1){ arr[i] -= 1; }
				}
			}
			if (arr[i] < 1){ arr[i] = 1; }
			if (arr[i] + i > n){
				ans += (arr[i]+i) - (n+1);
				arr[i] = n+1 - i;
			}
			while (arr[i] > 1){
				ans += 1;
				int p = i + arr[i];
				lazy[p] += 1;
				arr[i] -= 1;
			}
			//cout << i << endl;
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