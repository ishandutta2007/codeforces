#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define fsp fixed << setprecision(9)

typedef double long dl;

using namespace std;

const dl eps = 1e-9;
const dl INF = 1e7;

dl mod(pair <int, dl> a, pair <int, dl> b) {
	dl ax = a.first, ay = a.second, bx = b.first, by = b.second;
	return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, r;
	cin >> n >> r;
	vector <int> x(n);	
	for (int i = 0; i < n; i++)
		cin >> x[i];
	vector <dl> y(n);
	for (int i = 0; i < n; i++) {
		dl L = r, R = INF;
		for (int j = 0; j < i; j++)
			if (abs(x[i] - x[j]) <= 2 * r) 
				L = max(L, y[j]);
		for (int it = 0; it < 50; it++) {
			dl M = (L + R) / 2;
			bool tf = true;
			for (int j = 0; j < i; j++)
				if ((abs(x[i] - x[j]) <= 2 * r) && (mod({ x[j], y[j] }, { x[i], M }) + eps < 4 * r * r))
					tf = false;
			if (tf) R = M;
			else L = M;
			y[i] = M;
		}
	}
	for (int i = 0; i < n; i++)
		cout << fsp << y[i] << " ";
	return 0;
}