#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ll n, m, a;
	cin >> n >> m >> a;
	cout << ((n + a - 1) / a) * ((m + a - 1) / a);
	return 0;
}