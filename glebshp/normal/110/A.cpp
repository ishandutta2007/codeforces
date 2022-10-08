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
	//freopen("luck.in", "r", stdin);
	//freopen(".out", "w", stdout);

	long long n;

	cin >> n;
	int g = 0;
	while (n > 0)
	{
		g += (n % 10 == 4 || n % 10 == 7);
		n /= 10;
	}

	cout << ((g == 4 || g == 7) ? "YES" : "NO");

	return 0;
}