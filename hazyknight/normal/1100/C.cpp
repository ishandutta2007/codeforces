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

double n,r;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> r;
	cout << fixed << setprecision(10) << r * sin(acos(-1) / n) / (1 - sin(acos(-1) / n)) << endl;
	return 0;
}