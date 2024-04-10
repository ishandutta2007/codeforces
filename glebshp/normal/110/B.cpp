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
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << (char) ('a' + i % 4);
	}

	return 0;
}