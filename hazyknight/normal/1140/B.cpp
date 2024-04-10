#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

int T,n;

string s;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> s;
		int cnt1 = 0,cnt2 = 0;
		for (int i = 0;i < s.size();i++)
			if (s[i] == '<')
				cnt1++;
			else
				break;
		for (int i = s.size() - 1;i >= 0;i--)
			if (s[i] == '>')
				cnt2++;
			else
				break;
		cout << min(cnt1,cnt2) << endl;
	}
	return 0;
}