#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <string>

#define ll long long
#define mp make_pair
#define pb push_back


using namespace std;

int main() {
	ll ans = 0;
	int a[300005], n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort (a, a + n);
	ll sum = 0;
	for (int i = 0; i < n; i++) sum += a[i];
	ans += 2 * sum;
	for (int i = 0; i < n; i++){
		sum -= a[i];
		ans += sum;	
	}
	ans -= a[n - 1];
	cout << ans;
	return 0;
}