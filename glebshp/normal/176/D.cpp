#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 2010;
const int lsize = 1000 * 1000 + 100;
const int smsize = 26;
const int inf = 1000 * 1000 * 1000 * 2 + 100;

string str;
int lst[lsize][smsize];
int bg[size], ed[size];
int nums[size];
int ans[size][size];
int h[size][smsize];
int len[size], totsum[size];
int n, m;

inline int getinstr(int snum, int ps, int smb)
{
	if (ps >= len[snum])
		return inf;
	return lst[bg[snum] + ps][smb];
}

int getans(int pst, int smb)
{
	int lb = 0, rb = m + 1;
	int mid;
	while (lb < rb)
	{
		mid = (lb + rb) / 2;
		if (totsum[mid] > pst)
			rb = mid;
		else
			lb = mid + 1;
	}
	if (lb == m + 1)
		return inf;
	if (lb > 0)
	{
		mid = getinstr(nums[lb - 1], pst + 1 - totsum[lb - 1], smb);
		if (mid < inf)
			return mid + totsum[lb - 1];
	}
	if (h[lb][smb] < inf)
		return getinstr(nums[h[lb][smb]], 0, smb) + totsum[h[lb][smb]];
	return inf;
}

int main() {
	int ps = 0;

	//freopen("problem_d.in", "r", stdin);
	//freopen("problem_d.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		len[i] = str.length();
		bg[i] = ps;
		ed[i] = ps + str.length();
		ps += str.length();
		for (int j = 0; j < 26; j++)
			lst[ed[i] - 1][j] = inf;
		lst[ed[i] - 1][str[len[i] - 1] - 'a'] = str.length() - 1;
		for (int j = ed[i] - 2; j >= bg[i]; j--)
		{
			for (int h = 0; h < 26; h++)
				lst[j][h] = lst[j + 1][h];
			lst[j][str[j - bg[i]] - 'a'] = j - bg[i];
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> nums[i];
		nums[i]--;
	}
	totsum[0] = 0;
	for (int i = 0; i < m; i++)
		totsum[i + 1] = totsum[i] + len[nums[i]];
	totsum[m + 1] = inf + 10;
	for (int i = 0; i < 26; i++)
		h[m][i] = inf;
	for (int j = m - 1; j >= 0; j--)
		for (int i = 0; i < 26; i++)
			h[j][i] = (lst[bg[nums[j]]][i] == inf ? h[j + 1][i] : j);
	cin >> str;
	int sl = str.length();
	for (int i = 1; i <= sl; i++)
		ans[i][0] = inf;
	for (int i = 0; i <= sl; i++)
		ans[0][i] = -1;
	for (int i = 1; i <= sl; i++)
		for (int j = 1; j <= sl; j++)
			ans[i][j] = min(ans[i][j - 1], getans(ans[i - 1][j - 1], str[j - 1] - 'a'));
	for (int i = sl; i >= 0; i--)
		if (ans[i][sl] < inf)
		{
			cout << i << endl;
			return 0;
		}

	return 0;
}