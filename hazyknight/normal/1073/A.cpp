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

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0;i < s.size() - 1;i++)
		if (s[i] == s[i + 1])
			continue;
		else
		{
			cout << "YES" << endl;
			cout << s[i] << s[i + 1] << endl;
			return 0;
		}
	cout << "NO" << endl;
	return 0;
}