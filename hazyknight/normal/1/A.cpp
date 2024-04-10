#include <iostream>
#include <cmath>

using namespace std;

long long n,m,a;

int main()
{
	cin >> n >> m >> a;
	long long ansx = ((n % a == 0) ? n / a : n / a + 1);
	long long ansy = ((m % a == 0) ? m / a : m / a + 1);
	cout << ansx * ansy << endl;
	return 0;
}