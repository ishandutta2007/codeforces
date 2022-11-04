#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n;
int a[26];
int b[26];

string ans;

vector<string> S[105];

int main()
{
	cin >> n;
	cout << "? " << 1 << ' ' << n << endl;
	cout.flush();
	for (int i = 1;i <= n * (n + 1) / 2;i++)
	{
		string s;
		cin >> s;
		sort(s.begin(),s.end());
		S[s.size()].push_back(s);
	}
	if (n == 1)
	{
		cout << "! " << S[1][0] << endl;
		return 0;
	}
	cout << "? " << 2 << ' ' << n << endl;
	cout.flush();
	for (int i = 1;i <= (n - 1) * n / 2;i++)
	{
		string s;
		cin >> s;
		sort(s.begin(),s.end());
		for (int j = 0;j < S[s.size()].size();j++)
			if (S[s.size()][j] == s)
			{
				S[s.size()].erase(S[s.size()].begin() + j);
				break;
			}
	}
	ans = S[1][0];
	for (int i = 2;i <= n;i++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for (int j = 0;j < S[i - 1][0].size();j++)
			a[S[i - 1][0][j] - 'a']++;
		for (int j = 0;j < S[i][0].size();j++)
			b[S[i][0][j] - 'a']++;
		for (int j = 0;j < 26;j++)
			if (a[j] != b[j])
			{
				ans += char('a' + j);
				break;
			}
	}
	cout << "! " << ans << endl;
	return 0;
}