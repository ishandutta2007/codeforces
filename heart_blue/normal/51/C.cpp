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
	scanf("%d", &n);
	vector<int> v(n);
	for (auto& x : v)
		scanf("%d", &x);
	sort(v.begin(), v.end());
	double l = 0, r = 1e18;
	int cnt = 200;
	vector<double> ans;
	while (cnt--)
	{
		double mid = (l + r) / 2;
		vector<double> res;
		double pre = -1;
		for (auto& x : v)
		{
			if (x > pre)
			{
				pre = x + mid * 2;
				res.push_back(x + mid);
				if (res.size() == 4) break;
			}
		}
		if (res.size() <= 3) ans = res, r = mid;
		else l = mid;
	}
	printf("%.15f\n", r);
	while (ans.size() < 3) ans.push_back(v[0]);
	sort(ans.begin(), ans.end());
	for (auto& x : ans)
		printf("%.15f ", x);
	return 0;
}