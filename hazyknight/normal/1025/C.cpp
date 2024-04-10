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

string s;

int ans,f[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> s;
	int n = s.size();
	s += s;
	ans = max(ans,f[1] = 1);
	for (int i = 1;i < (n << 1);i++)
	{
		if (s[i] == s[i - 1])
			ans = max(ans,f[i] = 1);
		else
			ans = max(ans,f[i] = f[i - 1] + 1);
	}
	cout << min(ans,n) << endl;
	return 0;
}