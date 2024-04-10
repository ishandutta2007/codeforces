#include <bits/stdc++.h>
using namespace std;

#define MAXN 500

int N;
bool good[MAXN][2];
vector<int> ar;
multiset<int, greater<int> > table;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void erase_two(int x) {
	for (int i = 0; i < 2; i++) {
		table.erase(table.find(x));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N * N; i++) {
		int x;
		cin >> x;
		table.insert(x);
	}

	if (N == 1) {
		cout << *table.begin() << endl;
		return 0;
	}

	typedef multiset<int, greater<int> >::iterator mit;
	mit a = table.begin();
	ar.push_back(*a);
	table.erase(a);
	a = table.begin();
	ar.push_back(*a);
	table.erase(a);

	erase_two(gcd(ar[0], ar[1]));

	for (int c = 2; c < N; c++) {
		a = table.begin();
		ar.push_back(*a);
		table.erase(a);

		for (int i = 0; i < c; i++) {
			erase_two(gcd(ar[i], ar[c]));
		}
	}

	for (int i = 0; i < N; i++) {
		cout << ar[i] << ' ';
	}

	cout << endl;
	return 0;
}