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
const int N = 1e2 + 10;
vector<int> build(int x)
{
	vector<int> v;
	for (int i = 0; i <= 30; i++)
	{
		if (x >> i & 1)
			v.push_back(i);
	}
	return v;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a > b)
		{
			puts("NO");
			continue;
		}
		vector<int> v1, v2;
		v1 = build(a);
		v2 = build(b);
		int flag = 1;
		while (!v2.empty())
		{
			while (!v1.empty() && v1.back() > v2.back()) v1.pop_back();
			if (v1.empty())
			{
				flag = 0;
				break;
			}
			v1.pop_back();
			v2.pop_back();
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}