#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

const int MAXN = 2e5 + 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		bool tf = true;
		a.push_back(a[0]);
		for (int i = 1; i <= n; i++)
			if (a[i] != a[i - 1])
				tf = false;
		if (tf) {
			cout << 1 << endl;
			for (int i = 0; i < n; i++)
				cout << 1 << " ";
			cout << endl;
			continue;
		}
		tf = false;
		for (int i = 1; i <= n; i++)
			if (a[i] == a[i - 1])
				tf = true;
		if (!tf) {
			if (n % 2) {
				cout << 3 << endl;
				for (int i = 0; i < n / 2; i++)
					cout << 1 << " " << 2 << " ";
				cout << 3 << endl;
				continue;
			}
			cout << 2 << endl;
			for (int i = 0; i < n / 2; i++)
				cout << 1 << " " << 2 << " ";
			cout << endl;
			continue;
		}
		vector <int> color(n + 1);
		for (int i = 0; i <= n; i++) color[i] = i % 2;
		if (color[0] != color[n]) {
			int it = n;
			color[it] ^= 1;
			it--;
			while (a[it] != a[it + 1]) {
				color[it] ^= 1;
				it--;
			}
		}
		cout << 2 << endl;
		for (int i = 0; i < n; i++)
			cout << color[i] + 1 << " ";
		cout << endl;
	}
	return 0;
}

/*
112
8
13 13 9 12 13 1 13 1
19
18 8 15 5 8 4 18 16 11 5 9 4 17 14 16 13 2 17 2
12
8 10 5 5 2 3 13 11 2 9 1 13
7
5 6 6 1 3 5 4
3
1 1 1
3
1 1 2
3
1 1 3
3
1 2 1
3
1 2 2
3
1 2 3
4
3 2 2 3
4
1 3 2 3
4
2 3 2 3
4
3 3 2 3
4
1 1 3 3
4
2 1 3 3
4
3 1 3 3
4
1 2 3 3
4
2 2 3 3
4
3 2 3 3
3
1 3 1
4
1 3 3 3
4
2 3 3 3
4
3 3 3 3
3
1 3 2
3
1 3 3
3
2 1 1
3
2 1 2
3
2 1 3
3
2 2 1
3
2 2 2
3
2 2 3
3
2 3 1
3
2 3 2
3
2 3 3
3
3 1 1
3
3 1 2
3
3 1 3
*/