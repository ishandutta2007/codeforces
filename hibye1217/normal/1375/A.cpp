#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define fr first
#define sc second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int arr[120];

int main(){
	Fast;
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		for (int i = 1; i <= n; i++){
			if (i & 1) cout << abs(arr[i]) << ' ';
			else cout << -1*abs(arr[i]) << ' ';
		}
		cout << endl;
	}
}