#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define endl '\n'
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

ll arr[200020];

void Main(){
	for (ll i = 1; i <= 200000; i++){
		ll x = i/2, y = (i+1)/2;
		arr[i] = x*x + y*y;
		//if (i <= 10) cout << arr[i] << ' ';
	}
	//cout << endl;
	int t;
	cin >> t;
	while (t--){
		ld d, k;
		cin >> d >> k;
		ld res = (d/k)*(d/k);
		//cout << res << endl;
		int st = 1, ed = 200000, ans = 1;
		while (st <= ed){
			int mid = st + ed >> 1;
			if (arr[mid] <= res){
				ans = mid;
				st = mid+1;
			}
			else{
				ed = mid-1;
			}
		}
		//cout << ans << ' ';
		cout << (ans%2 == 0 ? "Utkarsh" : "Ashish") << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(15);
	Main();
}