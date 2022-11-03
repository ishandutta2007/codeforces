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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		map<int, int> mc;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			mc[x]++;
		}
		vector<int> v;
		for (auto &p : mc)
		{
			if (p.second >= 2) v.push_back(p.first);
			if (p.second >= 4) v.push_back(p.first);
		}
		LL U = INF, D = 1;
		int key = 0;
		for (int i =1; i < v.size(); i++)
		{
			int x = v[i - 1];
			int y = v[i];
			LL u = 1LL*(x + y)*(x+y);
			LL d = 1LL*x * y;
			if (u*D < U*d)
			{
				U = u;
				D = d;
				key = i;
			}
		}
		printf("%d %d %d %d\n", v[key - 1], v[key - 1], v[key], v[key]);
	}
	return 0;
}