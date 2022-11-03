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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	v[1].push_back(1);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		stack<int> s;
		s.push(0);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x == 1)
			{
				v[i] = v[s.top()];
				v[i].push_back(1);
			}
			else
			{
				while (v[s.top()].back() + 1 != x) s.pop();
				v[i] = v[s.top()];
				v[i].back()++;
				s.pop(); 
			}
			s.push(i);
			for (int j = 0; j < v[i].size(); j++)
			{
				printf("%d%c", v[i][j], ".\n"[j + 1 == v[i].size()]);
			}
		}
	}
	return 0;
}