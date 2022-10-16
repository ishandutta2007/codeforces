#include <bits/stdc++.h>

using namespace std;

int n;
long long k;

int left(int x) {
	if (x == 0) {
		return n - 1;
	}

	return x - 1;
}
int right(int x) {
	if (x == n - 1) {
		return 0;
	}

	return x + 1;
}

#ifdef LOCAL
vector<long long> __visi;
int __impost;
int __uzkl;
void init() {
	__uzkl = 0;
	cin >> n >> k;
	__visi.resize(n, k);
	cin >> __impost;
}
long long kiek(int w) {
	__uzkl++;
	long long t = __visi[w];
	cout << "? " << w + 1 << endl;
	vector<long long> v(n, 0);

	for (int i = 0; i < n; ++i) {
		if (i == __impost) {
			v[right(i)] += __visi[i];
		}
		else {
			v[left(i)] += __visi[i] / 2;
			v[right(i)] += __visi[i] - __visi[i] / 2;
		}
	}

	__visi = v;

	return t;
}
void answer(int w) {
	// for (auto &&i : __visi) {
	// 	cout << i << " ";
	// }
	//
	// cout << endl;
	cout << "! " << w + 1 << endl;
	cout << "Q:" << __uzkl << endl;
	assert(w == __impost);
	exit(0);
}
#else
void init() {
	cin >> n >> k;
}
long long kiek(int w) {
	cout << "? " << w + 1 << endl;
	long long x;
	cin >> x;
	return x;
}
void answer(int w) {
	cout << "! " << w + 1 << endl;
	exit(0);
}
#endif
/*input
20 2 1
*/
/*input
4 2 1
*/
/*input
1000 2 421
*/
/*input
100000 2 421
*/
/*input
100000 2 50100
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	init();
	int kur = 0;
	int time = 0;
	int q;
	while (true) {
		q = kiek(kur);

		if (q == k) {
			for (int i = 0; i < time; ++i) {
				kur = right(kur);
			}
			time++;
		}
		else {
			break;
		}
	}

	if (q < k) {
		while (kiek(kur) < k) {
			kur = right(kur);
		}

		answer(kur);
	}
	else {
		while (kiek(kur) > k) {
			kur = left(kur);
		}

		answer(kur);
	}
}