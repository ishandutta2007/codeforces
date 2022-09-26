#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const int MAXN = 5005;

int n;

int main()
{
	cin >> n;
	n &= 3;
	if (n == 0)
		cout << 0 << endl;
	if (n == 1)
		cout << 1 << endl;
	if (n == 2)
		cout << 1 << endl;
	if (n == 3)
		cout << 0 << endl;
	return 0;
}