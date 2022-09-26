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

string s,t;

int main()
{
	cin >> s;
	for (int i = 0;i < 5;i++)
	{
		cin >> t;
		if (s[0] == t[0] || s[1] == t[1])
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}