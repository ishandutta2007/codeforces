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
#include <cassert>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v;
	int n;
	scanf("%d", &n);
	a[0] = INF;
	a[n + 1] = -INF;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	int m;
	scanf("%d", &m);
	n++;
	while (m--)
	{
		int x;
		scanf("%d", &x);
		a[x] *= -1;
	}
	for (int i = 0; i <= n; i++)
	{
		if (a[i] >= 0)
		{
			v.push_back(i);
		}
		else
		{
			a[i] *= -1;
			vector<int> key;
			key.push_back(i);
			while (!v.empty())
			{
				if (key.empty()) break;
				
				if (a[key.back()] == a[v.back()])
				{
					int x = key.back();
					a[x] *= -1;
					v.pop_back();
					key.pop_back();
				}
				else
				{
					key.push_back(v.back());
					v.pop_back();
				}
			}
			if (!key.empty())
			{
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	for (int i = 1; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}