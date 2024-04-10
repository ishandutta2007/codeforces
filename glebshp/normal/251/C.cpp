#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1000 * 1000;

int ans[size + 10];
int k;
long long a, b;

int nod(int a, int b) {
	if (b == 0)
		return a;
	else
		return nod(b, a % b);
}

void calc_with_md(int mx, int md) {
	ans[0] = 0;

	for (int i = 1; i <= mx; i++) {
		ans[i] = ans[i - 1] + 1;

		for (int j = 2; j <= k; j++)
			if ((i - (i + md) % j) >= 0)
				ans[i] = min(ans[i], ans[i - (i + md) % j] + 1);
	}
}

int main() {
	//freopen("problem_c.in", "r", stdin);
	//freopen("problem_c.out", "w", stdout);
	
	int nd = 1;
	for (int i = 2; i <= 15; i++) {
		nd = nd * i / nod(nd, i);
	}

	cin >> a >> b >> k;
	swap(a, b);

	long long midans = 0;

	if (b - a >= size) {
		calc_with_md(nd, 0);

		midans = ans[b % nd];

		b -= b % nd;
		long long upb;
		if (a % nd == 0)
			upb = a;
		else
			upb = a + (nd - (a % nd));

		midans += ans[nd] * 1ll * ((b - upb) / nd - 1);
		b = upb + nd;
	}

	calc_with_md((int) (b - a), (int) (a % nd));

	cout << midans + ans[b - a] << endl;

	return 0;
}