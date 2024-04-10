#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);

void first_win()
{
	cout << "First" << endl;
	exit(0);
}

void second_win()
{
	cout << "Second" << endl;
	exit(0);
}

int main() {
	int xc1, xc2, yc1, yc2, n, m;

	//freopen("problem_c.in", "r", stdin);
	//freopen("problem_c.out", "w", stdout);
	cin >> n >> m >> xc1 >> yc1 >> xc2 >> yc2;
	int a = abs(xc1 - xc2), b = abs(yc1 - yc2);
	if (a > b)
		swap(a, b);
	if (a > 3)
		second_win();
	if (a == 3)
		if (b > 3)
			second_win();
		else
			first_win();
	if (a == 2)
		if (b > 4)
			second_win();
		else
			first_win();
	if (b > 4)
		second_win();
	else
		first_win();
	

	return 0;
}