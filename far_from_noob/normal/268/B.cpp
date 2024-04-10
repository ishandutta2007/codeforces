#include <iostream>
using namespace std;

int main() {
	long long  n;
	cin >> n;
	cout << (long long)(n)*(n+1)/2 + (long long)(n-2)*(n-1)*(n)/6;
	return 0;
}