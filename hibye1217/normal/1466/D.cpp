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

ll arr[100020];
int cnt[100020];
priority_queue<int> pq;

void Main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
		}
		ll ans = 0;
		for (int i = 1; i < n; i++){
			int x, y;
			cin >> x >> y;
			cnt[x] += 1;
			cnt[y] += 1;
			ans += arr[x] + arr[y];
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j < cnt[i]; j++){
				pq.push(arr[i]);
				ans -= arr[i];
			}
		}
		for (int k = 1; k < n; k++){
			cout << ans << ' ';
			if (!pq.empty()){
				ans += pq.top();
				pq.pop();
			}
		}
		cout << endl;
		memset(cnt, 0, sizeof(cnt));
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