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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		vector<int> v(k);
		for (auto& x : v)
			scanf("%d", &x);
		reverse(v.begin(), v.end());
		priority_queue<int> q;
		int sz = n * m - 3;
		int flag = 1;
		for (int i = k; i >= 1; i--)
		{
			while (!v.empty() && q.size() < sz)
			{
				q.push(v.back());
				v.pop_back();
			}
			if (q.top() != i)
			{
				flag = 0;
				break;
			}
			q.pop();
		}
		if (flag) puts("YA");
		else puts("TIDAK");
	}
	return 0;
}