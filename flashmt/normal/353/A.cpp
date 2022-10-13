#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int main()
{
	int n, upper = 0, lower = 0, oddEvenDomino = 0, x, y;
	cin >> n;
	while (n--)
	{
		cin >> x >> y;
		upper ^= x % 2;
		lower ^= y % 2;
		oddEvenDomino |= (x % 2) ^ (y % 2);
	}
	cout << (upper + lower ? (oddEvenDomino && upper == lower? 1 : -1) : 0) << endl;
}