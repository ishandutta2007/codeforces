#include <bits/stdc++.h>

using namespace std;

/*input
25
24114 46559 40804 40930 39129 49505 18453 33358 22440 29777 37814 35048 41988 47225 12324 47524 47055 14565 46508 14139 14908 19912 16369 22323 11922
45809 30314 23813 39806 37964 25473 14603 24414 32187 42137 30819 14382 47520 11653 21851 25587 14420 24131 32070 19898 13019 49551 20925 34197 38847
*/

const int sizes = 24 * 50000+1;

bitset<sizes> b[25];

using ll = long long;
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int *a = new int[2 * n];
	ll sum = 0;

	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	sort(a, a + 2 * n);

	ll pilnas = a[0] + a[1];

	sum -= pilnas;

	a = a + 2;
	// const ll size = 20;
	n--;
	b[0][0] = 1;

	for (int i = 0; i < 2 * n; i++) {
		for (int j = n; j > 0; j--) {
			b[j] |= b[j - 1] << a[i];
		}
	}

	ll ats;

	for (ats = sum / 2; !b[n][ats]; ats--) ;

	vector<int> pirm;
	vector<int> antr;
	int j = n;

	for (int i = 2 * n; i > 0; i--) {
		if (j > 0 and ats >= a[i - 1] and b[j - 1][ats - a[i - 1]]) {
			pirm.push_back(i - 1);
			ats -= a[i - 1];
			j--;
		}
		else {
			antr.push_back(i - 1);
		}
	}

	cout << a[-1] << " ";
	reverse(pirm.begin(), pirm.end());

	for (auto && i : pirm) {
		cout << a[i] << " ";
	}

	cout << endl;


	for (auto && i : antr) {
		cout << a[i] << " ";
	}

	cout << a[-2] << " ";
}