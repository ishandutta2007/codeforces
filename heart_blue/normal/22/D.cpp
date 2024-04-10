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
	int n;
	cin >> n;
	vector<pair<int, int>> vp;
	while (n--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if (l > r) swap(l, r);
		vp.emplace_back(r, l);
	}
	sort(vp.begin(), vp.end());
	int pre = -INF;
	vector<int> ans;
	for (auto& p : vp)
	{
		int l, r;
		tie(r, l) = p;
		if (l > pre)
		{
			pre = r;
			ans.push_back(pre);
		}
	}
	printf("%d\n", ans.size());
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}