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
const int N = 1e4 + 10;
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n = 250;
		MEM(cnt, 0);
		int sum = 0;
		while (n--)
		{
			int x;
			scanf("%d", &x);
			cnt[x]++;
			sum += x;
		}

		int p = sum / 250;
		int b = p / 5;
		for (int i = 1; i <= 2 * p; i++)
		{
			cnt[i] += cnt[i - 1];
		}
		int sum1 = 0;
		int sum2 = 0;
		vector<int> v;
		for (int i = b; i <= p * 2; i++)
		{
			int x = cnt[i] - cnt[i - b];
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size() / 2; i++) sum1 += v[i];
		for (int i = v.size() / 2; i < v.size(); i++) sum2 += v[i];
		if (sum2 > 4 * sum1) puts("poisson");
		else puts("uniform");

	}
	return 0;
}