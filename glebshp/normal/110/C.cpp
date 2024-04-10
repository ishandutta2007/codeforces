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
	//freopen("luck.out", "w", stdout);

	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		if (i * 4 <= n && (n - i * 4) % 7 == 0)
		{
			for (j = 0; j < i; j++)
				cout << "4";
			for (j = 0; j < (n - i * 4) / 7; j++)
				cout << "7";
			return 0;
		}
	}

	cout << "-1";

	return 0;
}