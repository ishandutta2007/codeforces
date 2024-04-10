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
#include <iomanip>
#include <bitset>

using namespace std;

int n,k,cur,ans;

string s;

int main()
{
	cin >> n >> k >> s;
	for (int i = 0;i < 26;i++)
	{
		int cnt = 0;
		cur = 0;
		for (int j = 0;j < s.size();j++)
			if (s[j] == 'a' + i)
				cnt++;
			else
			{
				cur += cnt / k;
				cnt = 0;
			}
		cur += cnt / k;
		ans = max(ans,cur);
	}
	cout << ans << endl;
	return 0;
}