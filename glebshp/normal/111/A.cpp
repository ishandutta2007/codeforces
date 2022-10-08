#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define pi 3.1415926535897932384626433832795

int main() {
	long long n, x, y;
	int i;
	
	//freopen("input.txt", "r", stdin);
	//freopen("ouput.txt", "w", stdout);

	cin >> n >> x >> y;
	if ((y < n) || (n - 1 + (y - n + 1) * (y - n + 1) < x))
		cout << -1;
	else
	{
		cout << (y - n + 1) << endl;
		for (i = 0; i < n - 1; i++)
			cout << 1 << endl;
	}

	return 0;
}