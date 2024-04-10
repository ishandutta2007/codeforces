// Codeforces Beta Round #15
// Problem E -- Triangles
#include <iostream>

#define m 1000000009

using namespace std;

int n;

int main()
{
	long long a = 1, b = 2, c = 4;
	for(cin >> n; n -= 2; c = (c * a) % m, b = (b + c) % m, a = (a * 2 + 3) % m);
	cout << (b * b + 1) * 2 % m << endl;
	return 0;
}