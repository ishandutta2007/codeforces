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

int prev[111][26], f[111][111][111], oldK[111][111][111];
string s1, s2, virus;

int match(string s, int i, int ch, int ii)
{
	if (ch != s[ii] - 'A') return 0;
	for (int j = 1; j < ii; j++)
		if (s[ii - j] != s[i - j + 1]) return 0;
	return 1;
}

string trace(int i, int j, int k)
{
	if (!i || !j) return "";
	if (i && f[i - 1][j][k] == f[i][j][k]) return trace(i - 1, j, k);
	if (j && f[i][j - 1][k] == f[i][j][k]) return trace(i, j - 1, k);
	return trace(i - 1, j - 1, oldK[i][j][k]) + s1[i];
}

int main()
{
	cin >> s1 >> s2 >> virus;
	int m = s1.size(), n = s2.size(), p = virus.size();
	s1 = "$" + s1; 
	s2 = "#" + s2;
	virus = "@" + virus;
	
	for (int i = 0; i < p; i++)
		for (int j = 0; j < 26; j++)
			if (j == virus[i + 1] - 'A') prev[i][j] = i + 1;
			else
				for (int ii = i; ii; ii--)
					if (match(virus, i, j, ii))
					{
						prev[i][j] = ii; break;
					}
				
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k < p && k <= m && k <= n; k++)
			{
				if (i < m && f[i][j][k] > f[i + 1][j][k]) f[i + 1][j][k] = f[i][j][k];
				if (j < n && f[i][j][k] > f[i][j + 1][k]) f[i][j + 1][k] = f[i][j][k];
				
				int kk = prev[k][s1[i + 1] - 'A'];
				
				if (i < m && j < n && s1[i + 1] == s2[j + 1] && f[i][j][k] + 1 > f[i + 1][j + 1][kk] && kk < p)
				{
					f[i + 1][j + 1][kk] = f[i][j][k] + 1;
					oldK[i + 1][j + 1][kk] = k;
				}
			}
			
	int ans = 0;
	for (int k = 0; k < p; k++) ans = max(ans, f[m][n][k]);
			
	if (!ans) 
	{
		puts("0");
		return 0;
	}
			
	string res = "";		
	for (int k = 0; k < p; k++)
		if (ans == f[m][n][k])
		{
			cout << trace(m, n, k) << endl;
			return 0;
		}
}