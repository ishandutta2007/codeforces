/*input
123456789123456898
700000000000000000
*/
#include <bits/stdc++.h>

using namespace std;
int kie[10] = {};
long long x, y;
vector<long long> yy;

long long find(long long d, int lik, bool did = false) {
	//cout << d << " " << lik << " " << yy[lik - 1] << " " << did << endl;

	if (lik == 0) {
		if (d <= y)
			return d;

		return -1;
	}

	if (did) {
		for (int i = 9; i >= 0; i--) {
			for (int k = 0; k < kie[i]; k++)
				d = d * 10 + i;
		}

		if (d <= y)
			return d;

		return -1;
	}

	long long t = -1;

	for (int i = min(9ll, yy[lik - 1]); i > (d == 0 ? 0 : -1); i--) {
		if (kie[i] > 0) {
			if (i == yy[lik - 1]) {
				kie[i]--;
				t = max(t, find(d * 10 + i, lik - 1, false));
				kie[i]++;
			}
			else {
				kie[i]--;
				t = max(t, find(d * 10 + i, lik - 1, true));
				kie[i]++;
				break;
			}
		}
	}

	return t;
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> x >> y;
	int vis = 0;

	long long ty = y;

	while (x > 0) {
		kie[x % 10]++;
		x /= 10;

		if (x != 0)
			yy.push_back(ty % 10);
		else
			yy.push_back(ty);

		ty /= 10;
		vis++;
	}

	/*for (auto && x : yy)
		cout << x << " ";

	cout << endl;*/

	cout << find(0, vis);


	return 0;
}