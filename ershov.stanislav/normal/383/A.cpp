#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

long long n, s, res;

int main() {
	cin >> n;
	for (int i=0, s=0; i<n; i++) {
		int b;
		cin >> b;
		if (b) s++;
		else res+=s;
	}
	cout << res;
	return 0;
}