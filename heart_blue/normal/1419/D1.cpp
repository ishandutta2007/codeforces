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
typedef long long ll;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int sz1 = (n - 1) / 2;
	int sz2 = n - sz1;
	vector<int> v(a + 1, a + n + 1);
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < v.size(); i++)
	{
		if (i * 2 + 1 > n) break;
		ans[i * 2 + 1] = v[i];
		v[i] = 0;
	}
	int ptr = 0;
	int tot = 0;
	for (int i = 2; i + 1 <= n; i += 2)
	{
		while (ptr < v.size())
		{
			if (v[ptr] == 0)
			{
				ptr++;
				continue;
			}
			if (v[ptr] < ans[i - 1] && v[ptr] < ans[i + 1])
			{
				tot++;
				break;
			}
			else
				continue;
		}
		if (ptr == v.size()) break;
		ans[i] = v[ptr];
		v[ptr] = 0;
		ptr++;
	}
	ptr = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ans[i]) continue;
		while (ptr < v.size() && v[ptr] == 0) ptr++;
		ans[i] = v[ptr];
		ptr++;
	}
	printf("%d\n", tot);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}