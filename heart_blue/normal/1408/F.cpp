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
const int N = 1e6 + 10;
map<pair<int, int>, int> mc;
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> ans;
	int o = 1;
	while (o < n) o *= 2;
	o /= 2;
	vector<pair<int, int>> key;
	key.emplace_back(1, o);
	key.emplace_back(n - o + 1, n);
	for (auto& p : key)
	{
		int l, r;
		tie(l, r) = p;
		for (int o = 2; o <= r - l + 1; o *= 2)
		{
			for (int i = l; i <= r; i += o)
			{
				for (int j = 0; j < o / 2; j++)
				{
					ans.emplace_back(i + j, i + j + o / 2);
				}
			}
		}
	}
	printf("%d\n", ans.size());
	for (auto& p : ans)
		printf("%d %d\n", p.first, p.second);
	return 0;
}