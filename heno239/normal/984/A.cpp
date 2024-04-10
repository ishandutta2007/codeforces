#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double PI = 3.14159265358979;
const double E = 2.718281828459045;
const double root2 = sqrt(2);
typedef pair<int, int> P;
typedef unsigned int ui;
int main() {
	int n; cin >> n;
	int a[1000]; int A;
	for (int i = 0; i < n; i++) {
		cin >> A; a[i] = A;
	}
	sort(a, a + n);
	if (n % 2 == 0) {
		cout << a[n / 2 - 1] << endl;
	}
	else {
		cout << a[n / 2] << endl;
	}
	return 0;
}