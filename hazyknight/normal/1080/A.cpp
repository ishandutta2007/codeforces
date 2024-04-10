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
#include <iomanip>

using namespace std;

long long n,k;

int main()
{
	cin >> n >> k;
	cout << (n * 2 - 1) / k + 1 + (n * 5 - 1) / k + 1 + (n * 8 - 1) / k + 1 << endl;
	return 0;
}