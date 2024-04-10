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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int cur = 1;
	vector<int> ans;
	while (n > 1)
	{
		int maxv = 0;
		int k = 0;
		for (int i = 2; i <= INF; i++)
		{
			if (maxv <= n / i && k <= i)
			{
				maxv = n / i;
				k = i;
			}
			else break;
		}
		for (int i = n; i > maxv; i--) ans.push_back(cur);
		n = maxv;
		cur *= k;
	}
	ans.push_back(cur);
	for (auto &x : ans) printf("%d ", x);
	return 0;
}