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
#include <complex>

using namespace std;

string s;

int main()
{
	cin >> s;
	int cnt0 = 0,cnt1 = 0;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == '1')
		{
			cnt0++;
			cnt0 %= 4;
			if (cnt0 == 1)
				cout << 1 << ' ' << 1 << endl;
			if (cnt0 == 2)
				cout << 1 << ' ' << 3 << endl;
			if (cnt0 == 3)
				cout << 2 << ' ' << 1 << endl;
			if (cnt0 == 0)
				cout << 2 << ' ' << 3 << endl;
		}
		else
		{
			cnt1++;
			cnt1 %= 4;
			if (cnt1 == 1)
				cout << 3 << ' ' << 1 << endl;
			if (cnt1 == 2)
				cout << 3 << ' ' << 2 << endl;
			if (cnt1 == 3)
				cout << 3 << ' ' << 3 << endl;
			if (cnt1 == 0)
				cout << 3 << ' ' << 4 << endl;
		}
	}
	return 0;
}