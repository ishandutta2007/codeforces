/*input
2 2
-2000 -2000
3998000 4000000

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int k, n;
	cin >> k >> n;
	long long task[k];
	long long tur[n];

	for (int i = 0; i < k; i++)
		cin >> task[i];

	for (int i = 0; i < n; i++)
		cin >> tur[i];

	sort(tur, tur + n);

	set<long long>pradin;

	for (int i = 0; i < k; i++) {
		long long dab = tur[0];
		set<long long>nauj{tur[0]};

		for (int j = i; j > 0; j--) {
			dab -= task[j];
			nauj.insert(dab);
		}

		long long prad = dab - task[0];

		dab = tur[0];
		//cout << endl;

		for (int j = i + 1; j < k; j++) {
			dab += task[j];
			nauj.insert(dab);
		}

		bool ar = 1;

		for (int i = 0; i < n; i++) {
			if (nauj.count(tur[i]) == 0)
				ar = false;
		}

		if (ar)
			pradin.insert(prad);
	}

	cout << pradin.size();

	return 0;
}