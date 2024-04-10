#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

ll ans;
ll f[MAXN][11];

string s;

int main()
{
	ios::sync_with_stdio(0);
	cin >> s;
	for (int i = 0;i < s.size() - 1;i++)
	{
		if (s[i] != '0')
			f[i][s[i] - '0']++;
		for (int j = s[i + 1] - '0' + 1;j < 11;j++)
			f[i + 1][(j * (j - 1) / 2 + 10 + s[i + 1] - '0') % 11] += f[i][j];
	}
	if (s[s.size() - 1] != '0')
		f[s.size() - 1][s[s.size() - 1] - '0']++;
	for (int i = 0;i < s.size();i++)
		for (int j = 0;j < 11;j++)
			ans += f[i][j];
	cout << ans << endl;
	return 0;
}