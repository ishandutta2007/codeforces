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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int check(string& s1, string& s2)
{
	int n = s1.length();
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt += s1[i] != s2[i];
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
		int n, m;
		cin >> n >> m;
		vector<string> vs(n);
		for (auto& s : vs) cin >> s;
		string str;
		int ok = 0;
		for (int i = 0; i < m; i++)
		{
			str = vs[0];
			ok = 0;
			for (char c = 'a'; c <= 'z'; c++)
			{
				str[i] = c;
				ok = 1;
				for (int j = 0; j < n; j++)
				{
					if (check(str, vs[j]) > 1)
					{
						ok = 0;
						break;
					}
				}
				if (ok) break;
			}
			if (ok) break;
		}
		if (ok) puts(str.c_str());
		else puts("-1");
	}
	return 0;
}