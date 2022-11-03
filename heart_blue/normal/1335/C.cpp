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
const int N = 1e5 + 10;
char str[N];
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
		map<int, int> mc;
		while (n--)
		{
			int x;
			scanf("%d", &x);
			mc[x]++;
		}
		for (auto& p : mc)
			v.push_back(p.second);
		sort(v.begin(), v.end());
		int ans = 0;
		int maxv = 0;
		for (int i = 0; i < v.size(); i++)
		{
			maxv = max(maxv, v[i] - 1);
			if (i + 1 == v.size()) break;
			ans = max(ans, min(i + 1, v.back()));
		}
		ans = max(ans, min(int(v.size()), maxv));
		printf("%d\n", ans);
	}
	return 0;
}