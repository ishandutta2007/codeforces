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
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int maxv = 0;
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		cnt[x]++;
		maxv = max(maxv, x);
	}
	int tot = 0;
	tuple<int,int,int> ans = { -1,-1,-1 };
	int sum = 0;
	for (int i = 1; i <= maxv + 1; i++)
	{
		if (cnt[i])
		{
			ans = max(ans, { cnt[i],i,i });
		}
		if (cnt[i] && cnt[i + 1])
		{
			ans = max(ans, { cnt[i] + cnt[i + 1],i,i });
		}
		if (cnt[i] >= 2) tot++, sum += cnt[i];
		else
		{
			int l = i - tot;
			int r = i - 1;
			if (cnt[l - 1]) sum += cnt[--l];
			if (cnt[r + 1]) sum += cnt[++r];
			ans = max(ans, { sum,l,r });
			sum = 0;
			tot = 0;
		}
	}
	int res, l, r;
	tie(res, l, r) = ans;
	printf("%d\n", res);
	for (int i = l; i <= r; i++) printf("%d ", i);
	for (int i = r; i >= l; i--)
	{
		while (--cnt[i])
			printf("%d ", i);
	}
	return 0;
}