#include <iostream>

using namespace std;

const long double eps = 1e-12;

int main() {
	int p, d, t, f, c; cin >> p >> d >> t >> f >> c;

	if (p >= d) {
		cout << 0 << "\n";
		return 0;
	}

	int bijou = 0;
	
	long double alpha = t * p;

	while (alpha + eps < c) {
		long double meet = alpha / (long double)(d - p);
		meet *= d;
		
		//cerr << alpha << " " << meet << "\n";
		if (meet + eps < c) {
			++bijou;
			long double time = alpha / (long double)(d - p);
			alpha += time * 2.0 * p + f * p;
		} else {
			break;
		}
	}

	cout << bijou;
}