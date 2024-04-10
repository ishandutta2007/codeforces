
#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
#define MAX 1010101
int main(void) {
	lld T;
	cin >> T;
	while (T-- > 0) {
		lld n, x;
		cin >> n >> x;
		lld i;
		lld a;
		lld sum1 = 0, sum2 = 0;
		for (i = 1; i <= n; i++) {
			cin >> a;
			sum1 += (a%x == 0) ? a / x : a / x + 1;
			sum2 += a;
		}
		cout << ((sum2%x == 0) ? sum2 / x : sum2 / x + 1) << ' ' << sum1 << endl;
	}
}