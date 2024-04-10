#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

typedef pair<int, int> point;
pair<int, int> A[4];
pair<int, int> B[4];
point CA, CB;

int ccw(point a, point b, point c) {
	return (b.first - a.first) * (c.second - a.second)
			- (b.second - a.second) * (c.first - a.first);
}

bool in(point p, point* sq) {
	int p1 = ccw(sq[0], sq[1], p);
	int p2 = ccw(sq[1], sq[2], p);
	int p3 = ccw(sq[2], sq[3], p);
	int p4 = ccw(sq[3], sq[0], p);
	
	return (p1 <= 0 && p2 <= 0 && p3 <= 0 && p4 <= 0)
		|| (p1 >= 0 && p2 >= 0 && p3 >= 0 && p4 >= 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < 4; i++) {
		cin >> A[i].first >> A[i].second;
		CA.first += A[i].first;
		CA.second += A[i].second;
		A[i].first *= 4;
		A[i].second *= 4;
	}
	
	for (int i = 0; i < 4; i++) {
		cin >> B[i].first >> B[i].second;
		CB.first += B[i].first;
		CB.second += B[i].second;
		B[i].first *= 4;
		B[i].second *= 4;
	}

	bool ok = false;
	for (int i = 0; i < 4; i++) {
		if (in(A[i], B)) {
			ok = true;
		}
		if (in(B[i], A)) {
			ok = true;
		}
	}

	if (in(CA, B))
		ok = true;
	if (in(CB, A))
		ok = true;

	cout << (ok?"YES":"NO") << endl;
	return 0;
}