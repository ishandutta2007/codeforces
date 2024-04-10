/*input
2
2 2
2 1 1 1
1 2 2 2
1 0 0 0
*/
#include <bits/stdc++.h>

using namespace std;

struct sof {
	int x1, y1, x2, y2;
	int kair = 0, des = 0, auks = 0, zem = 0;
};

int main () {
	int d, n, m;
	cin >> d >> n >> m;
	sof mas[d];

	for (int i = 0; i < d; i++) {
		cin >> mas[i].x1 >> mas[i].y1 >> mas[i].x2 >> mas[i].y2;

		if (mas[i].x1 > mas[i].x2 or mas[i].y1 > mas[i].y2) {
			swap(mas[i].x1, mas[i].x2);
			swap(mas[i].y1, mas[i].y2);
		}
	}

	{
		int te[100001] = {};

		for (int i = 0; i < d; i++)
			te[mas[i].x1]++;

		for (int i = 1; i <= 100000; i++)
			te[i] += te[i - 1];

		for (int i = 0; i < d; i++) {
			if (mas[i].x2 == mas[i].x1)
				mas[i].kair = te[mas[i].x1 - 1];
			else
				mas[i].kair = te[mas[i].x1] - 1;
		}
	}

	{
		int te[100001] = {};

		for (int i = 0; i < d; i++)
			te[mas[i].x2]++;

		for (int i = 99999; i >= 0; i--)
			te[i] += te[i + 1];

		for (int i = 0; i < d; i++) {
			if (mas[i].x2 == mas[i].x1)
				mas[i].des = te[mas[i].x2 + 1];
			else
				mas[i].des = te[mas[i].x2] - 1;
		}
	}

	{
		int te[100001] = {};

		for (int i = 0; i < d; i++)
			te[mas[i].y1]++;

		for (int i = 1; i <= 100000; i++)
			te[i] += te[i - 1];

		for (int i = 0; i < d; i++){
			if (mas[i].y2 == mas[i].y1)
				mas[i].auks = te[mas[i].y1 - 1];
			else
				mas[i].auks = te[mas[i].y1] - 1;
		}
	}

	{
		int te[100001] = {};

		for (int i = 0; i < d; i++)
			te[mas[i].y2]++;

		for (int i = 99999; i >= 0; i--)
			te[i] += te[i + 1];

		for (int i = 0; i < d; i++) {
			if (mas[i].y2 == mas[i].y1)
				mas[i].zem = te[mas[i].y2 + 1];
			else
				mas[i].zem = te[mas[i].y2] - 1;
		}
	}

	int kair = 0, des = 0, auks = 0, zem = 0;
	cin >> kair >> des >> auks >> zem;

	for (int i = 0; i < d; i++) {
		//cout << i << " " << mas[i].kair << " " << mas[i].des << " " << mas[i].auks << " " << mas[i].zem << endl;;

		if (mas[i].kair == kair and mas[i].des == des and mas[i].auks == auks and mas[i].zem == zem) {
			cout << i + 1 << endl;
			return 0;
		}
	}

	cout << -1;

	return 0;
}