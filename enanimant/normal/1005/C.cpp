#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<long long> p2;
	for (int i = 0; i <= 31; i++) {
		p2.push_back(1 << i);
	}

	sort(a.begin(), a.end());

	int removed = 0;
	for (int i = 0; i < n; i++) {
		bool keep = false;
		for (int p : p2) {
			if (p == a[i] + a[i]) {
				auto er = equal_range(a.begin(), a.end(), a[i]);
//				cout << "er.second, er.first: " << er.second - a.begin() << ' ' << er.first - a.begin() << '\n';
				if (er.second - er.first >= 2) {
					keep = true;
					break;
				}
			}
			else if (binary_search(a.begin(), a.end(), p - a[i])) {
				keep = true;
				break;
			}
		}
		if (!keep) {
			removed++;
		}
	}

	cout << removed << '\n';


	return 0;
}