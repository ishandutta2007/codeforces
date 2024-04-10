// I LOVE WRONG ANSWER
// GIVE ME WRONG ANSWER ON PRETEST 3
// 11th WRONG ANSWER
// SORRY FOR THE QUEUE THOUGH

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

int arr[300020];
bool chk1[300020], chk2[300020];

void Main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
		}
		int res = 0;
		for (int i = 2; i < n; i++){
			chk1[i] = arr[i-1] < arr[i] && arr[i] > arr[i+1];
			chk2[i] = arr[i-1] > arr[i] && arr[i] < arr[i+1];
			if (chk1[i] || chk2[i]){
				res += 1;
			}
		}
		int ans = res;
		for (int i = 1; i <= n; i++){
			int tmp = arr[i];
			if (i != 1){
				int dif = 0;
				arr[i] = arr[i-1];
				for (int d = max(i-3, 2); d <= min(i+3, n-1); d++){
					if (chk1[d] && !(arr[d-1] < arr[d] && arr[d] > arr[d+1])){
						dif += 1;
					}
					if (!chk1[d] && (arr[d-1] < arr[d] && arr[d] > arr[d+1])){
						dif -= 1;
					}
					if (chk2[d] && !(arr[d-1] > arr[d] && arr[d] < arr[d+1])){
						dif += 1;
					}
					if (!chk2[d] && (arr[d-1] > arr[d] && arr[d] < arr[d+1])){
						dif -= 1;
					}
				}
				ans = min(ans, res-dif);
				arr[i] = tmp;
			}
			if (i != n){
				int dif = 0;
				arr[i] = arr[i+1];
				for (int d = max(i-3, 2); d <= min(i+3, n-1); d++){
					if (chk1[d] && !(arr[d-1] < arr[d] && arr[d] > arr[d+1])){
						dif += 1;
					}
					if (!chk1[d] && (arr[d-1] < arr[d] && arr[d] > arr[d+1])){
						dif -= 1;
					}
					if (chk2[d] && !(arr[d-1] > arr[d] && arr[d] < arr[d+1])){
						dif += 1;
					}
					if (!chk2[d] && (arr[d-1] > arr[d] && arr[d] < arr[d+1])){
						dif -= 1;
					}
				}
				ans = min(ans, res-dif);
				arr[i] = tmp;
			}
		}
		cout << ans << endl;
		memset(arr, 0, sizeof(arr));
		memset(chk1, 0, sizeof(chk1));
		memset(chk2, 0, sizeof(chk2));
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