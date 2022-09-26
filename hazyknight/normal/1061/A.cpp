#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

long long n,m;

int main()
{
	cin >> n >> m;
	cout << (m / n + (m % n > 0)) << endl;
	return 0;
}