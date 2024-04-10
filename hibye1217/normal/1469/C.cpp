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

pll arr[200020];
ll res[200020];
bool chk[200020];

bool cmp(pll a, pll b){
	return a.fr > b.fr;
}

void Main(){
	int t;
	cin >> t;
	while (t--){
		ll n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++){
			cin >> arr[i].fr;
			arr[i].sc = i;
		}
		sort(arr+1, arr+n+1, cmp);
		bool ans = true;
		for (int i = 1; i <= n; i++){
			ll idx = arr[i].sc;
			chk[idx] = true;
			res[idx] = arr[i].fr;
			if (chk[idx+1]){
				res[idx] = max(res[idx], res[idx+1] - k + 1);
			}
			if (chk[idx-1]){
				res[idx] = max(res[idx], res[idx-1] - k + 1);
			}
			ans &= (res[idx] - arr[i].fr < k);
			if (idx == 1 || idx == n){
				ans &= res[idx] == arr[i].fr;
			}
		}
		cout << (ans ? "YES" : "NO") << endl;
		memset(chk, 0, sizeof(chk));
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