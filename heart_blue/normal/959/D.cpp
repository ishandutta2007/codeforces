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
const int N = 1e7 + 10;
const int M = 2e5 + 10;
int a[N];
vector<int> v[M];
void init()
{
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		for (int j = i; j < N; j += i)
		{
			if (j < M) v[j].push_back(i);
			a[j] = 1;
		}
		a[i] = 0;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	init();
	scanf("%d", &n);
	int k = 2;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		int flag = 1;
		for (auto &d : v[x])
		{
			if (a[d] == 1)
			{
				flag = 0;
			}
		}
		if (flag == 1)
		{
			printf("%d ", x);
			for (auto &d : v[x])
			{
				a[d] = 1;
			}
			continue;
		}
		while (1)
		{
			x++;
			int f = 1;
			for (auto &d : v[x])
			{
				if (a[d])
				{
					f = 0;
					break;;
				}
			}
			if (f) break;
		}
		printf("%d ", x);
		for (auto &d : v[x]) a[d] = 1;
		i++;
		while (i < n)
		{
			i++;
			while (a[k]) k++;
			a[k] = 1;
			printf("%d ", k);
		}
	}
	return 0;
}