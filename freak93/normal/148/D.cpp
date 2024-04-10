#include <iostream>
#include <vector>

using namespace std;

long double mat[1005][1005][2];

long double answer(int w, int b, int who) {
	if (mat[w][b][who] > -0.5)
		return mat[w][b][who];

	if (who == 0) {
		if (w == 0)
			return (mat[w][b][who] = 0);
		if (b == 0)
			return (mat[w][b][who] = 1);

		return (mat[w][b][who] = w / (long double)(w + b) + b / (long double)(w + b) * (1.0 - answer(w, b - 1, 1)));
	}

	if (w == 0 || b == 0)
		return 1;

	long double rez = w / (long double)(w + b);

	long double chance = b / (long double)(w + b);

	// A white mice runs
	rez += chance * w / (long double)(w + b - 1) * (1.0 - answer(w - 1, b - 1, 0));

	// Black mice
	rez += chance * (b - 1) / (long double)(w + b - 1) * (b < 2 ? 0 : (1.0 - answer(w, b - 2, 0)));
	return (mat[w][b][who] = rez);
}
		
int main() {
	int w, b; cin >> w >> b;
	for (int i = 0; i <= w; ++i)
		for (int j = 0; j <= b; ++j)
			mat[i][j][0] = mat[i][j][1] = -1;

	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(9);
	cout << answer(w, b, 0);
}