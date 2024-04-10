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
const int N = 5e5 + 10;

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
		vector<int> v;
		set<int> s;
		for (int i = 1; i <= n; i++)
			s.insert(i);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x > n) v.push_back(x);
			else if (s.count(x)) s.erase(x);
			else v.push_back(x);
		}
		sort(v.begin(), v.end());
		int cnt = 0;
		while (!v.empty())
		{
			int x = v.back();
			v.pop_back();
			int y = *s.rbegin();
			s.erase(y);
			if ((x - 1) / 2 >= y) cnt++;
			else
			{
				cnt = -1;
				break;
			}
		}
		printf("%d\n", cnt);

	}
	return 0;
}