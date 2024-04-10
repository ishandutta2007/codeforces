#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

typedef double long dl;

using namespace std;

const dl eps = 1e-9;
const dl INF = 1e9;

dl mod(pair <dl, dl> A, pair <dl, dl> B) {
	dl Ax = A.first, Ay = A.second, Bx = B.first, By = B.second;
	return sqrt((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By));
}

int main() {
	int n;
	dl vb, vs;
	cin >> n >> vb >> vs;
	dl xf, yf;
	pair <dl, int> ans = { INF, -1 };
	vector <dl> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	cin >> xf >> yf;
	for (int i = 1; i < n; i++) {
		dl t = (x[i] / vb) + mod({ x[i], 0 }, { xf, yf }) / vs;
		if (ans.first + eps > t) ans = { t, i + 1 };
	}
	cout << ans.second;
	return 0;
}