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

int T,n,a[3];

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> a[0] >> a[1] >> n;
		a[2] = a[0] ^ a[1];
		cout << a[n % 3] << endl;
	}
	return 0;
}