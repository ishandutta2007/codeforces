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
const int N = 1e5 + 10;
vector<int> v[N];
int sz[N];
int flag[N];
void init()
{
	for (int i = 2; i < N; i++)
	{
		for (int j = i; j < N; j += i) v[j].push_back(i);
	}
}
int check(int x)
{
	for (auto &d : v[x])
	{
		if (sz[d]) return sz[d];
	}
	return 0;
}
void add(int x, int o)
{
	for (auto &d : v[x])
	{
		sz[d] = o;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	init();
	cin >> n >> m;
	while (m--)
	{
		char op;
		int x;
		cin >> op >> x;
		if (op == '+')
		{
			if (flag[x])
			{
				puts("Already on");
				continue;
			}
			int res = check(x);
			if (res == 0)
			{
				add(x, x);
				flag[x] = 1;
				puts("Success");
			}
			else
			{
				printf("Conflict with %d\n", res);
			}
		}
		else
		{
			if (flag[x] == 0)
			{
				puts("Already off");
			}
			else
			{
				add(x, 0);
				flag[x] = 0;
				puts("Success");
			}
		}
	}
	return 0;
}