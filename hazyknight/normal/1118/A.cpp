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

int q;

long long n,a,b;

int main()
{
	cin >> q;
	while (q--)
	{
		cin >> n >> a >> b;
		cout << min(n * a,(n >> 1) * b + (n & 1) * a) << endl;
	}
	return 0;
}