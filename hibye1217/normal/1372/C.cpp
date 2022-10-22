#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define fr first
#define sc second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int arr[200020];

int main(){
	Fast;
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		int ans = 0;
		for (int i = 1; i <= n; i++){
			if (arr[i] != i && arr[i-1] == i-1) ans += 1;
		}
		cout << min(ans, 2) << endl;
	}
}