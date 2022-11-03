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
const int N = 2e3 + 10;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if (flag[x]) continue;
		flag[x] = 1;
		vp.emplace_back(x, i);
	}
	while (q--)
	{
		int x;
		scanf("%d", &x);
		int pos = -1;
		for (int i = 0; i < vp.size(); i++)
		{
			if (vp[i].first == x)
			{
				pos = i;
				break;
			}
			else
			{
				vp[i].second++;
			}
		}
		printf("%d ", vp[pos].second);
		vp.erase(vp.begin() + pos);
		vp.insert(vp.begin(), make_pair(x, 1));
	}
	return 0;
}