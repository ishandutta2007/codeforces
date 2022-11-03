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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
vector<string> vs;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vs.resize(n + 1);
	MEM(flag, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> vs[i];
	}
	int l = 0;
	string pattern;
	while (m--)
	{
		int x;
		cin >> x;
		flag[x] = 1;
		if (l != 0)
		{
			if (l != vs[x].length())
			{
				puts("No");
				return 0;
			}
		}
		l = vs[x].length();
		pattern = vs[x];
	}
	for (int i = 1; i <= n; i++)
	{
		if (flag[i])
		{
			for (int j = 0; j < l; j++)
			{
				if (pattern[j] != vs[i][j])
				{
					pattern[j] = '?';
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!flag[i])
		{
			if (vs[i].length() != l) continue;
			int error = 1;
			for (int j = 0; j < l; j++)
			{
				if (pattern[j] == '?') continue;
				if (pattern[j] != vs[i][j])
				{
					error = 0;
				}
			}
			if (error)
			{
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	puts(pattern.c_str());

	
	return 0;
}