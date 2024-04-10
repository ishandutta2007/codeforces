/*input
2
abcde
xyzab
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	deque<string> mas;
	int suraid[256];
	bool nereik[n] = {};

	for (int i = 0; i < 256; i++)
		suraid[i] = -1;

	for (int w = 0; w < n; w++) {
		string a;
		cin >> a;

		bool kie[256] = {};

		for (int i = 0; i < a.size(); i++) {
			if (kie[a[i]]) {
				cout << "NO";
				return 0;
			}

			kie[a[i]] = true;
		}

		bool cont = false;

		for (int j = 0; j < a.size(); j++) {
			if (suraid[a[j]] != -1) {
				int in = suraid[a[j]];

				if (a.size() > mas[in].size()) {
					if (a.find(mas[in]) != -1) {
						nereik[in] = true;

						for (auto && x : mas[in])
							suraid[x] = -1;
					}
				}
				else if (a.size() <= mas[in].size()) {
					if (mas[in].find(a) != -1) {
						cont = true;
						break;
					}
				}
			}
		}

		if (cont)
			continue;

		//cout << a << endl;

		int prsize = a.size();

		if (suraid[a[0]] != -1) {
			int in = suraid[a[0]];
			int fr = mas[in].find(a[0]);
			assert(fr != -1);

			for (int l = 0; l < a.size(); l++) {
				if (fr + l < mas[in].size() and mas[in][fr + l] != a[l]) {
					cout << "NO";
					return 0;
				}
			}

			a = mas[in].substr(0, fr) + a;
			nereik[in] = true;

			for (auto && x : mas[in])
				suraid[x] = -1;
		}

		if (prsize != 1 and suraid[a.back()] != -1) {
			int in = suraid[a.back()];
			int fr = mas[in].find(a.back());
			assert(fr != -1);

			for (int l = 0; l < a.size(); l++) {
				if (fr - int(a.size()) + l + 1 >= 0 and mas[in][fr - a.size() + l + 1] != a[l]) {
					cout << "NO";
					return 0;
				}
			}

			a = a + mas[in].substr(fr + 1);
			nereik[in] = true;

			for (auto && x : mas[in])
				suraid[x] = -1;
		}

		for (auto && x : a) {
			if (suraid[x] != -1) {
				cout << "NO";
				return 0;
			}

			suraid[x] = mas.size();
		}

		for (int i = 0; i < 256; i++)
			kie[i] = false;

		for (int i = 0; i < a.size(); i++) {
			if (kie[a[i]]) {
				cout << "NO";
				return 0;
			}

			kie[a[i]] = true;
		}

		mas.push_back(a);
	}

	vector<string> ats;

	for (int i = 0; i < mas.size(); i++) {
		if (!nereik[i])
			ats.push_back(mas[i]);
	}

	sort(ats.begin(), ats.end());

	string u = "";

	for (auto && x : ats)
		u += x;

	bool kie[256] = {};

	for (int i = 0; i < u.size(); i++) {
		if (kie[u[i]]) {
			cout << u << endl;
			return 1;
		}

		kie[u[i]] = true;
	}

	cout << u << endl;

	return 0;
}