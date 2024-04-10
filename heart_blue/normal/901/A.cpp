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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
vector<int> v[N];
int p1[N];
int p2[N];
int f[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int h;
	cin >> h;
	for (int i = 0; i <= h; i++) cin >> a[i];
	int key = -1;
	for (int i = 0; i < h; i++)
	{
		if (a[i] > 1 && a[i + 1] > 1)
		{
			key = i;
			break;
		}
	}
	if (key == -1)
	{
		puts("perfect");
		return 0;
	}
	int k = 1;
	for (int i = 0; i <= h; i++)
	{
		f[i] = k;
		for (int j = 1; j <= a[i]; j++)
		{
			v[i].push_back(k++);
		}
	}
	puts("ambiguous");
	printf("0");
	int o = 2;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= a[i]; j++)
		{
			printf(" %d", f[i - 1]);
		}
	}
	puts("");
	o = 2;
	printf("0");
	for (int i = 1; i <= h; i++)
	{
		int oo[2] = { f[i - 1],f[i] - 1 };
		for (int j = 1; j <= a[i]; j++)
		{
			printf(" %d", oo[j & 1]);
		}
	}
	puts("");
	return 0;
}