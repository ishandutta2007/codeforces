#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<long long> fib(100);

	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i <= 88; ++i)
		fib[i] = fib[i - 1] + fib[i - 2];
	
	int N;
	cin >> N;
	while (N--) {
		long long x;
		cin >> x;
		vector<int> a(100, 0);
		for (int i = 88; i > 0; --i)
			if (fib[i] <= x)
				a[i] = 1, x -= fib[i];

		int last = 0;
		if (a[1] > 0)
			last = 1;
		if (a[2] > 0)
			last = 2;

		long long solda = 0, solnu = 1;
		for (int i = 3; i <= 88; ++i)
			if (a[i] == 1) {
				long long tsolda = 0, tsolnu = solda + solnu;
				tsolda = (i - last - 1) / 2 * solnu;
				tsolda += (i - last) / 2 * solda;
				solda = tsolda;
				solnu = tsolnu;
				//cerr << i << " -> " << solda << " " << solnu << "\n";
				last = i;
			}

		cout << solda + solnu << "\n";
	}
}