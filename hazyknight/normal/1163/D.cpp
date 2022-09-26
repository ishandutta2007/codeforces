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

const int MAXN = 1005;
const int MAXM = 55;
const int INF = (1 << 30) - 1;

int ans;
int nxts[MAXM];
int nxtt[MAXM];
int f[MAXN][MAXM][MAXM];

string S,s,t;

void getnxt(string cur,int *nxt)
{
	nxt[0] = nxt[1] = 0;
	for (int i = 1,j = 0;i < cur.size();i++)
	{
		while (j && cur[i] != cur[j])
			j = nxt[j];
		if (cur[i] == cur[j])
			j++;
		nxt[i + 1] = j;
	}
}

void trans(int i,int j,int k,char c)
{
	int cnt = f[i][j][k];
	while (j && s[j] != c)
		j = nxts[j];
	if (s[j] == c)
		j++;
	if (j == s.size())
	{
		j = nxts[j];
		cnt++;
	}
	while (k && t[k] != c)
		k = nxtt[k];
	if (t[k] == c)
		k++;
	if (k == t.size())
	{
		k = nxtt[k];
		cnt--;
	}
	f[i + 1][j][k] = max(f[i + 1][j][k],cnt);
}

int main()
{
	cin >> S >> s >> t;
	getnxt(s,nxts);
	getnxt(t,nxtt);
	for (int i = 0;i <= S.size();i++)
		for (int j = 0;j < s.size();j++)
			for (int k = 0;k < t.size();k++)
				f[i][j][k] = -INF;
	f[0][0][0] = 0;
	for (int i = 0;i < S.size();i++)
		for (int j = 0;j < s.size();j++)
			for (int k = 0;k < t.size();k++)
				if (f[i][j][k] != -INF)
				{
					if (S[i] != '*')
						trans(i,j,k,S[i]);
					else
					{
						for (char c = 'a';c <= 'z';c++)
							trans(i,j,k,c);
					}
				}
	ans = -INF;
	for (int i = 0;i < s.size();i++)
		for (int j = 0;j < t.size();j++)
			ans = max(ans,f[S.size()][i][j]);
	cout << ans << endl;
	return 0;
}