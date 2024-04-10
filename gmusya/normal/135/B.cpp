#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

typedef long long ll;

using namespace std;

struct vec {
	ll x, y;
	void read() {
		cin >> x >> y;
	}
	vec operator - (vec a) {
		return { x - a.x, y - a.y };
	}
	ll operator * (vec a) {
		return x * a.x + y * a.y;
	}
	ll operator % (vec a) {
		return x * a.y - y * a.x;
	}
	ll mod() {
		return x * x + y * y;
	}
};

int main() {
	vector <vec> a(8);
	for (int i = 0; i < 8; i++)
		a[i].read();
	vector <int> p(8);
	iota(p.begin(), p.end(), 0);
	do {
		vector <pair <int, vec>> sq(4), rect(4);
		for (int i = 0; i < 4; i++)
			sq[i] = { p[i], a[p[i]] };
		for (int i = 0; i < 4; i++)
			rect[i] = { p[i + 4], a[p[i + 4]] };
		sq.push_back(sq[0]), sq.push_back(sq[1]), rect.push_back(rect[0]), rect.push_back(rect[1]);
		bool tf = true;
		for (int i = 1; i < 5; i++) {
			ll c = (sq[i + 1].second - sq[i].second) * (sq[i - 1].second - sq[i].second);
			if (c) tf = false;
		}
		for (int i = 1; i < 5; i++) {
			ll c = (rect[i + 1].second - rect[i].second) * (rect[i - 1].second - rect[i].second);
			if (c) tf = false;
		}
		for (int i = 1; i < 5; i++) 
			if ((sq[i + 1].second - sq[i].second).mod() != (sq[i].second - sq[i - 1].second).mod()) 
				tf = false;
		if (tf) {
			cout << "YES" << endl;
			for (int i = 0; i < 4; i++) cout << sq[i].first + 1 << " ";
			cout << endl;
			for (int i = 0; i < 4; i++) cout << rect[i].first + 1 << " ";
			return 0;
		}
	} while (next_permutation(p.begin(), p.end()));
	cout << "NO";
	return 0;
}