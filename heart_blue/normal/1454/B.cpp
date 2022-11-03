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
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		cin >> n;
		int id = -1;
		int minv = INF;
		map<int, int> mc;
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			mc[x]++;
			a[i] = x;
		}
		for (int i = 1; i <= n; i++)
		{
			if (mc[a[i]] > 1) continue;
			if (minv > a[i]) minv = a[i], id = i;
		}
		printf("%d\n", id);
	}
	return 0;
}