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
int flag[N];
int pos[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int cur = 0;
	while (n--)
	{
		string str;
		cin >> str;
		if (str[0] == 'a')
		{
			int x;
			cin >> x;
			int cnt = 0;
			int key = 0;
			for (int i = 1; i <= m; i++)
			{
				if (flag[i] == 0) cnt++;
				else cnt = 0;
				if (cnt == x)
				{
					key = i - x + 1;
					break;
				}
			}
			if (key == 0)
			{
				puts("NULL");
				continue;
			}
			cur++;
			for (int i = key; i < key + x; i++) flag[i] = cur;
			pos[cur] = key;
			printf("%d\n", cur);
		}
		if (str[0] == 'e')
		{
			int x;
			cin >> x;
			
			if (x < 0 || x >= N || pos[x] == 0)
			{
				puts("ILLEGAL_ERASE_ARGUMENT");
				continue;
			}
			for (int i = 1; i <= m; i++) if (flag[i] == x) flag[i] = 0;
			pos[x] = 0;
		}
		if (str[0] == 'd')
		{
			int cur = 1;
			for (int i = 1; i <= m; i++)
			{
				if (flag[i]) swap(flag[cur++], flag[i]);
			}
			for (int i = m; i > 0; i--)
			{
				pos[flag[i]] = i;
			}
		}
	}
	return 0;
}