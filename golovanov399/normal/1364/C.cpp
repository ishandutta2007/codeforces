#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	vector<int> b(n, n);
	vector<int> free_places;
	int last = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] > last) {
			b[i] = last;
			++last;
		} else {
			free_places.push_back(i);
		}
		while (last < a[i]) {
			if (free_places.empty()) {
				cout << "-1\n";
				return 0;
			}
			b[free_places.back()] = last++;
			free_places.pop_back();
		}
	}
	for (int x : b) {
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}