#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e6 + 10;
char str[N];
char s[N];
int d[N];
void build(int n)
{
	s[0] = '!';
	for (int i = 1; i <= n; i++)
	{
		s[2 * i - 1] = str[i];
		s[2 * i] = '*';
	}
	s[2 * n] = '#';
}
int check(int l, int r)
{
	int cnt = 0;
	while (l < r)
	{
		if (str[l] == str[r]) cnt++;
		else break;
		l++, r--;
	}
	return cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%s", str + 1);
		int n = strlen(str + 1);
		int key = check(1, n);
		int l = key + 1;
		int r = n - key;
		l = l * 2 - 1;
		r = r * 2 - 1;
		build(n);
		d[1] = 0;
		int o = 1;
		int maxv = -1;
		int k = 0;
		for (int i = 1; i <= n * 2 - 1; i++)
		{
			if (o + d[o] >= i) d[i] = min(o + d[o] - i, d[2 * o - i]);
			else d[i] = 0;
			int x = d[i];
			while (s[i + x] == s[i - x]) x++;
			d[i] = x - 1;
			if (i + d[i] > o + d[o]) o = i;
			if (i - d[i] <= l || i + d[i] >= r)
			{
				if (maxv < min(i - 1, n * 2 - 1 - i))
				{
					maxv = min(i - 1, n * 2 - 1 - i);
					k = i;
				}
			}
		}
		string s1, s2;
		l = 1, r = 2 * n - 1;
		while (l < k - d[k] && r > k + d[k])
		{
			if (isalpha(s[l]))
			{
				s1.push_back(s[l]);
				s2.push_back(s[r]);
			}
			l++, r--;
		}
		for (int i = d[k]; i >= 0; i--)
		{
			if (isalpha(s[k + i]))
			{
				s1.push_back(s[k + i]);
				if (i) s2.push_back(s[k + i]);
			}
		}
		reverse(s2.begin(), s2.end());
		printf("%s%s\n", s1.c_str(), s2.c_str());
	}
	return 0;
}