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

int n,ans;

string s[505];

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> s[i];
	for (int i = 1;i < n - 1;i++)
		for (int j = 1;j < n - 1;j++)
			if (s[i][j] == 'X' && s[i - 1][j - 1] == 'X' && s[i + 1][j - 1] == 'X' && s[i + 1][j + 1] == 'X' && s[i - 1][j + 1] == 'X')
				ans++;
	cout << ans << endl;
	return 0;
}