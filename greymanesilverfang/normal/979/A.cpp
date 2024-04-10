#include <iostream>
using namespace std;

int main()
{
	long long n; cin >> n;
	cout << (n == 0 ? 0 : (n + 1) / (n % 2 + 1));
	return 0;
}