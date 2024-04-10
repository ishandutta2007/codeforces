#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <set>
#include <map>

using namespace std;

vector<int> arr;

int XOR(int a, int b) {
	cout << "XOR " << a << " " << b << endl;
	int x;
	cin >> x;
	return x;
}

int OR(int a, int b) {
	cout << "OR " << a << " " << b << endl;
	int x;
	cin >> x;
	return x;
}

int AND(int a, int b) {
	cout << "AND " << a << " " << b << endl;
	int x;
	cin >> x;
	return x;
}

vector<int> x;

int MyXor(int i, int j) {
	return x[i] ^ x[j];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	mt19937_64 rnd(time(nullptr));
	int n;
	cin >> n;
	x.resize(n);
	for (int i = 1; i < n; ++i) {
		x[i] = XOR(1, i + 1);
	}
	int m = n - 1;
	while (true) {
		vector<int> y(n);
		int pos = rnd() % n;
		for (int i = 0; i < n; ++i) {
			y[i] = MyXor(i, pos);
		}
		map<int, set<int>> values;
		for (int i = 0; i < n; ++i) {
			if (i != pos) {
				values[y[i]].insert(i);
			}
		}
		set<int> tried;
		for (int i = 0; i < n; ++i) {
			if (i == pos) {
				continue;
			}
			if (tried.find(y[i]) != tried.end()) {
				continue;
			}
			tried.insert(y[i]);
			int mask = (m - y[i]);
			for (int submask = mask; submask >= 0; submask = mask & (submask - 1)) {
				if (values.find(submask) != values.end()) {
					while ((submask & y[i]) != 0) {
						cout << submask << ' ' << y[i];
						return 0;
					}
					auto& now = values[submask];
					auto it = now.begin();
					while (*it == pos && it != now.end()) {
						++it;
					}
					if (it == now.end()) {
						continue;
					}
					int A = *it;
					int val = AND(pos + 1, A + 1);
					int result = 0;
					for (int j = 1; j < n; j *= 2) {
						if ((y[A] & j) == 0) {
							result += (val & j);
						}
					}
					int B = i;
					val = AND(pos + 1, B + 1);
					for (int j = 1; j < n; j *= 2) {
						if ((y[B] & j) == 0 && (y[A] & j) != 0) {
							result += (val & j);
						}
					}
					cout << "! ";
					for (int j = 0; j < n; ++j) {
						cout << (y[j] ^ result) << ' ';
					}
					return 0;
				}
				if (submask == 0) {
					break;
				}
			}
		}
	}
	return 0;
}