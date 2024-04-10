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

string s;

int n;

int main()
{
	cin >> n >> s;
	for (int i = 0;i < n;i++)
		if (i == n - 1 || s[i] > s[i + 1])
		{
			s.erase(s.begin() + i);
			break;
		}
	cout << s << endl;
	return 0;
}