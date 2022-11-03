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
const int N = 2e6 + 10;
void check(vector<int>& v, int flag = 1)
{
	int x = v.back();
	v.pop_back();
	int y = v.back();
	v.pop_back();
	if(flag) printf("%d %d\n", x, y);
}
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
		vector<int> v1, v2;
		n *= 2;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x & 1) v1.push_back(i);
			else v2.push_back(i);
		}
		if (v1.size() & 1)
		{
			v1.pop_back();
			v2.pop_back();
		}
		else if (v1.size() >= 2)
		{
			check(v1, 0);
		}
		else
		{
			check(v2, 0);
		}
		while (!v1.empty())
			check(v1);
		while (!v2.empty())
			check(v2);
	}
	return 0;
}