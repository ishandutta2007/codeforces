#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

string s;
int n, tr[50500][55], f[50500][55], a[50500], F[55], idF[55], next[50500][26], last[26];

vector <int> trace(int i, int j)
{
	if (!j) return vector <int>();
	vector <int> res = trace(tr[i][j], j - 1);
	res.push_back(a[i]);
	return res;
}

int main()
{
	cin >> s;
	n = s.size();
	for (int i = 1; i <= n; i++)
	{
		a[i] = s[i - 1] - 'a';
		last[a[i]] = i;
		for (int j = 0; j < 26; j++) next[i][j] = last[j];
	}
	
	memset(f, -1, sizeof(f));
	F[0] = n;
	for (int i = 1; i <= n; i++)
		for (int j = 50; j; j--)
			if (F[j - 1])
			{
				int id = next[F[j - 1]][a[i]];
				if (id > i)
				{
					f[i][j] = id - 1;
					tr[i][j] = idF[j - 1];
					if (id - 1 > F[j]) F[j] = id - 1, idF[j] = i;
				}
			}
			
	for (int j = 50; j; j--)
	{
		for (int i = 1; i <= n; i++)
			if (f[i][j] >= 0 && i < f[i][j])
			{
				vector <int> ans = trace(i, j);
				for (int k = 0; k < int(ans.size()); k++) cout << char(ans[k] + 'a');
				if (j < 50) cout << char(a[f[i][j]] + 'a');
				reverse(ans.begin(), ans.end());
				for (int k = 0; k < int(ans.size()); k++) cout << char(ans[k] + 'a');
				return 0;
			}
			
		for (int i = 1; i <= n; i++)
			if (f[i][j] >= 0)
			{
				vector <int> ans = trace(i, j);
				for (int k = 0; k < int(ans.size()); k++) cout << char(ans[k] + 'a');
				reverse(ans.begin(), ans.end());
				for (int k = 0; k < int(ans.size()); k++) cout << char(ans[k] + 'a');
				return 0;
			}
	}
	
	cout << s[0] << endl;
}