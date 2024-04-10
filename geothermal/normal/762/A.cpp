#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;

	vector<long long> v;
	for (long long i = 1; i < sqrt(n); i++) {
		if (n % i == 0) {
			v.push_back(i);
		}
		
	}
	
	bool isSq = false;
	if (n == (long long) sqrt(n) * (long long) sqrt(n)) {
		isSq = true;
		v.push_back((long long) sqrt(n));
	}

	for (long long i = (long long) v.size() - 1 - isSq; i >= 0; i--) {
		v.push_back(n / v.at(i));
	}
	
	if (k > v.size()) {
		cout << "-1" << endl;
	} else {
		cout << v.at(k - 1) << endl;
	}

	
}