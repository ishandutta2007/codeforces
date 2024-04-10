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
const int N = 1e5 + 10;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		string str;
		scanf("%d", &n);
		cin >> str;
		int cnt = count(str.begin(), str.end(), 'M');
		if (cnt * 3 != n)
		{
			puts("NO");
			continue;
		}
		queue<int> q;
		memset(flag, 0, sizeof(int) * n);
		int ok = 1;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == 'T') q.push(i);
			else
			{
				if (q.empty())
				{
					ok = 0;
					break;
				}
				flag[q.front()] = 1;
				q.pop();
			}
		}
		while (!q.empty())
			q.pop();
		for (int i = n - 1; i >= 0; i--)
		{
			if (str[i] == 'T') q.push(i);
			else
			{
				if (q.empty())
				{
					ok = 0;
					break;
				}
				flag[q.front()] = 1;
				q.pop();
			}
		}
		if (ok) puts("YES");
		else puts("NO");
	}
	return 0;
}