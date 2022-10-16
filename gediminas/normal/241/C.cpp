/*input
80 72 9
15 T 8210 15679
10 F 11940 22399
50 T 30600 44789
50 F 32090 36579
5 F 45520 48519
120 F 49250 55229
8 F 59700 80609
35 T 61940 64939
2 T 92540 97769
*/
#include <bits/stdc++.h>

using namespace std;

struct veidr {
	int v, a, b;
	bool operator<(const veidr &o)const {
		return a < o.a;
	}
};

int main () {
	int a, c, n;
	cin >> a >> c >> n;

	vector<veidr> veid[2];
	// 0 - virsus, 1 - apacia

	for (int i = 0; i < n; i++) {
		int v;
		char c;
		cin >> v >> c;
		int k = 0;

		if (c == 'F')
			k = 1;

		veid[k].push_back(veidr());
		veid[k].back().v = v;
		cin >> veid[k].back().a >> veid[k].back().b;
	}

	sort(veid[0].begin(), veid[0].end());
	sort(veid[1].begin(), veid[1].end());

	long long ats = 0;

#define constanta 100

	for (int i = 2; i < constanta; i += 2) {
		long long ats1 = 0;
		long double x = i * 100 - a + c;
		long double sant = 100000.0l / x;
		vector<veidr>::iterator poin[2] = {veid[0].begin(), veid[1].begin()};
		bool kur = 0;

		long double yk = sant * (100 - a);

		while (poin[kur] != veid[kur].end() and poin[kur]->b < yk)
			poin[kur]++;

		if (poin[kur] == veid[kur].end())
			continue;

		if (poin[kur]->a <= yk and yk <= poin[kur]->b) {
			ats1 += poin[kur]->v;
			poin[kur]++;
		}
		else
			continue;

		bool blog = false;

		for (int j = 1; j < i; j++) {
			kur ^= 1;
			yk = sant * (100 - a + j * 100);

			while (poin[kur] != veid[kur].end() and poin[kur]->b < yk)
				poin[kur]++;

			if (poin[kur] == veid[kur].end()) {
				blog = true;
				break;
			}

			if (poin[kur]->a <= yk and yk <= poin[kur]->b) {
				ats1 += poin[kur]->v;
				poin[kur]++;
			}
			else {
				blog = true;
				break;
			}

		}

		if (blog)
			continue;

		ats = max(ats, ats1);
	}

	for (int i = 1; i < constanta; i += 2) {
		long long ats1 = 0;
		long double x = a + c + (i - 1) * 100;
		long double sant = 100000.0l / x;
		vector<veidr>::iterator poin[2] = {veid[0].begin(), veid[1].begin()};
		bool kur = 1;

		long double yk = sant * a;

		while (poin[kur] != veid[kur].end() and poin[kur]->b < yk)
			poin[kur]++;

		if (poin[kur] == veid[kur].end())
			continue;

		if (poin[kur]->a <= yk and yk <= poin[kur]->b) {
			ats1 += poin[kur]->v;
			poin[kur]++;
		}
		else
			continue;

		bool blog = false;

		for (int j = 1; j < i; j++) {
			kur ^= 1;
			yk = sant * (a + j * 100);

			while (poin[kur] != veid[kur].end() and poin[kur]->b < yk)
				poin[kur]++;

			if (poin[kur] == veid[kur].end()) {
				blog = true;
				break;
			}

			if (poin[kur]->a <= yk and yk <= poin[kur]->b) {
				ats1 += poin[kur]->v;
				poin[kur]++;
			}
			else {
				blog = true;
				break;
			}

		}

		if (blog)
			continue;


		//cout << i << " " << ats1 << endl;

		ats = max(ats, ats1);
	}

	for (int i = 1; i < constanta; i += 2) {
		long long ats1 = 0;
		long double x = (i + 1) * 100 - a - c;
		long double sant = 100000.0l / x;
		vector<veidr>::iterator poin[2] = {veid[0].begin(), veid[1].begin()};
		bool kur = 0;

		long double yk = sant * (100 - a);

		while (poin[kur] != veid[kur].end() and poin[kur]->b < yk)
			poin[kur]++;

		if (poin[kur] == veid[kur].end())
			continue;

		if (poin[kur]->a <= yk and yk <= poin[kur]->b) {
			ats1 += poin[kur]->v;
			poin[kur]++;
		}
		else
			continue;

		bool blog = false;

		for (int j = 1; j < i; j++) {
			kur ^= 1;
			yk = sant * (100 - a + j * 100);

			while (poin[kur] != veid[kur].end() and poin[kur]->b < yk)
				poin[kur]++;

			if (poin[kur] == veid[kur].end()) {
				blog = true;
				break;
			}

			if (poin[kur]->a <= yk and yk <= poin[kur]->b) {
				ats1 += poin[kur]->v;
				poin[kur]++;
			}
			else {
				blog = true;
				break;
			}

		}

		if (blog)
			continue;

		ats = max(ats, ats1);
	}

	for (int i = 2; i < constanta; i += 2) {
		long long ats1 = 0;
		long double x = i * 100 + a - c;
		long double sant = 100000.0l / x;
		vector<veidr>::iterator poin[2] = {veid[0].begin(), veid[1].begin()};
		bool kur = 1;

		long double yk = sant * a;

		while (poin[kur] != veid[kur].end() and poin[kur]->b < yk)
			poin[kur]++;

		if (poin[kur] == veid[kur].end())
			continue;

		if (poin[kur]->a <= yk and yk <= poin[kur]->b) {
			ats1 += poin[kur]->v;
			poin[kur]++;
		}
		else
			continue;

		bool blog = false;

		for (int j = 1; j < i; j++) {
			kur ^= 1;
			yk = sant * (a + j * 100);

			while (poin[kur] != veid[kur].end() and poin[kur]->b < yk)
				poin[kur]++;

			if (poin[kur] == veid[kur].end()) {
				blog = true;
				break;
			}

			if (poin[kur]->a <= yk and yk <= poin[kur]->b) {
				ats1 += poin[kur]->v;
				poin[kur]++;
			}
			else {
				blog = true;
				break;
			}

		}

		if (blog)
			continue;

		ats = max(ats, ats1);
	}


	cout << ats;

	return 0;
}