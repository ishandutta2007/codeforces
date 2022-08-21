#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef unsigned int ui;
int main() {
	int n, k;
	cin >> n >> k;
	int i;
	int z[100000]; int t[100000]; int Z; int T;
	for (i = 0; i < n; i++) {
		cin >> Z; z[i] = Z;
	}
	for (i = 0; i < n; i++) {
		cin >> T; t[i] = T;
	}
	int sum, ma;
	sum = 0; ma = 0;
	for (i = 0; i < n; i++) {
		if (t[i] == 1)sum += z[i];
	}
	for (i = 0; i < k; i++) {
		if (t[i] == 0)sum += z[i];
	}
	ma = max(ma, sum);
	for (i = 1; i + k - 1 < n; i++) {
		if (t[i + k - 1] == 0) {
			sum += z[i + k - 1];
		}
		if (t[i - 1] == 0) {
			sum -= z[i - 1];
		}
		ma = max(ma, sum);
	}
	cout << ma << endl;
	return 0;
}