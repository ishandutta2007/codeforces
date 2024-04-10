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
	int n, m;
	int a[1000] = {}; int A;
	cin >> n >> m;
	int i,j;
	int sum = 0;
	for (i = 0; i < m; i++) {
		cin >> A;
		a[A - 1]++;
		bool f = true;
		for (j = 0; j < n; j++) {
			if (a[j] == 0)f = false;
		}
		if (f) {
			sum++;
			for (j = 0; j < n; j++) {
				a[j]--;
			}
		}
	}
	cout << sum << endl;
	return 0;
}