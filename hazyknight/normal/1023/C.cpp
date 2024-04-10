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

int n,k,cnt;

string s;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k >> s;
	for (int i = 0;i < n;i++)
	{
		if (k == cnt)
		{
			while (k)
			{
				k--;
				cout << ')';
			}
			break;
		}
		cout << s[i];
		if (s[i] == '(')
			cnt++;
		else
			cnt--;
		k--;
	}
	cout << endl;
	return 0;
}