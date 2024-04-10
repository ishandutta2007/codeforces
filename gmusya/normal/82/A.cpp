#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	ll cnt = 1;
	ll Sheldon = 1, Leonard = 2, Penny = 3, Rajesh = 4, Howard = 5;
	while ((Howard + cnt - 1) < n) {
		Sheldon += cnt * 5;
		cnt *= 2;
		Leonard = Sheldon + cnt;
		Penny = Leonard + cnt;
		Rajesh = Penny + cnt;
		Howard = Rajesh + cnt;
		//cout << Sheldon << " " << Leonard << " " << Penny << " " << Rajesh << " " << Howard << endl;
	}
	if (n < Leonard) {
		cout << "Sheldon";
		return 0;
	}
	if (n < Penny) {
		cout << "Leonard";
		return 0;
	}
	if (n < Rajesh) {
		cout << "Penny";
		return 0;
	}
	if (n < Howard) {
		cout << "Rajesh";
		return 0;
	}
	cout << "Howard";
	return 0;
}