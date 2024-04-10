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

int a[5];

bool cnt[10];

string s,t;

int main()
{
	cin >> s;
	for (int i = 0;i < s.size();i++)
	{
		if ((s[i] == '1' || s[i] == '6' || s[i] == '8' || s[i] == '9') && !cnt[s[i] - '0'])
			cnt[s[i] - '0'] = 1;
		else
			t += s[i];
	}
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	if (!t.size() || t[0] == '0')
	{
		cout << "1869" << t << endl;
		return 0;
	}
	int res = 0;
	for (int i = 0;i < t.size();i++)
		res = (res * 10 + t[i] - '0') % 7;
	a[1] = 1;
	a[2] = 6;
	a[3] = 8;
	a[4] = 9;
	do
	{
		int res2 = 0;
		for (int i = 1;i <= 4;i++)
			res2 = (res2 * 10 + a[i]) % 7;
		if ((res * 10000 + res2) % 7 == 0)
		{
			cout << t;
			for (int i = 1;i <= 4;i++)
				cout << a[i];
			cout << endl;
			return 0;
		}
	}while (next_permutation(a + 1,a + 5));
	return 0;
}