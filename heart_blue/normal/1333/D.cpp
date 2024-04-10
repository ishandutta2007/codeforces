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
char str[N];
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", str + 1);
	int o = 0;
	LL tot = 0;
	while (1)
	{
		o++;
		auto& vp = v[o];
		for (int i = 1; i < n; i++)
		{
			if (str[i] == 'R' && str[i + 1] == 'L')
			{
				swap(str[i], str[i + 1]);
				vp.push_back(i);
				i++;
			}
		}
		if (vp.empty()) break;
		tot += vp.size();
	}
	o--;
	if (o > k || tot < k) puts("-1"), exit(0);
	for (int i = 1; i <= o; i++)
	{
		while (k > o - i + 1)
		{
			if (v[i].empty()) break;
			printf("%d %d\n", 1, v[i].back());
			v[i].pop_back();
			k--;
		}
		if (v[i].empty()) continue;
		printf("%d", v[i].size());
		for (auto& x : v[i]) printf(" %d", x);
		puts("");
		k--;
	}
	return 0;
}