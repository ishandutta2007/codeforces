#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n;

string s;

bool mark[26];

int main()
{
	cin >> n >> s;
	if (n == 1)
	{
		cout << "Yes" << endl;
		return 0;
	}
	for (int i = 0;i < s.size();i++)
	{
		if (mark[s[i] - 'a'])
		{
			cout << "Yes" << endl;
			return 0;
		}
		mark[s[i] - 'a'] = true;
	}
	cout << "No" << endl;
	return 0;
}