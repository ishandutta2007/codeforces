#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n,k;

int main()
{
	cin >> n >> k;
	if (k == 1)
	{
		for (int j = 0;j < n;j++)
			cout << (j == 0);
		cout << endl;
		return 0;
	}
	int t = (n - k) / 2;
	string s;
	for (int j = 0;j < n;j++)
		s += char(!(j % (t + 1) == 0) + '0');
	cout << s << endl;
	return 0;
}