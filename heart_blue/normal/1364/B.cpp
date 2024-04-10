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
const LL INF = 1e9 + 9;
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
		vector<int> v;
		int n;
		scanf("%d", &n);
		while (n--)
		{
			int x;
			scanf("%d", &x);
			int sz = v.size();
			if (sz <= 1)
			{
				v.push_back(x);
				continue;
			}
			if (v[sz - 2] < v[sz - 1] && v[sz - 1] < x) v.pop_back();
			else if (v[sz - 2] > v[sz - 1] && v[sz - 1] > x) v.pop_back();
			v.push_back(x);
		}
		printf("%d\n", v.size());
		for (int i = 0; i < v.size(); i++)
			printf("%d%c", v[i], " \n"[i + 1 == v.size()]);
	}
	return 0;
}