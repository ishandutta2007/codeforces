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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e5 + 10;
int flag[N];
vector<int> v1, v2;
int a[N];
int b[N];
map<int, int> ms;
vector<int> v;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int tot = min(m, N);
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
		if (a[i] <= tot) flag[a[i]] = 1;
		ms[a[i]] ++;
		if (ms[a[i]] > 1)
		{
			v.push_back(i);
		}
		else
		{
			if (a[i] & 1) sum1++;
			else sum2++;
		}
	}
	for (int i = 1; i <= tot; i++)
	{
		if (flag[i]) continue;
		if (i & 1) v1.push_back(i);
		else v2.push_back(i);
	}
	if (v.size() > v1.size() + v2.size())
	{
		puts("-1");
		return 0;
	}
	for (auto &x : v)
	{
		if (sum1 > sum2)
		{
			if (!v2.empty())
			{
				a[x] = v2.back();
				v2.pop_back();
				sum2++;
			}
			else
			{
				a[x] = v1.back();
				v1.pop_back();
				sum1++;
			}
		}
		else
		{
			if (!v1.empty())
			{
				a[x] = v1.back();
				v1.pop_back();
				sum1++;
			}
			else
			{
				a[x] = v2.back();
				v2.pop_back();
				sum2++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (sum1 < sum2 && a[i] % 2 == 0)
		{
			if (v1.empty())
			{
				cout << -1 << endl;
				return 0;
			}
			a[i] = v1.back();
			sum1++;
			sum2--;
			v1.pop_back();
		}
		if (sum1 > sum2 && a[i] % 2 == 1)
		{
			if (v2.empty())
			{
				cout << -1 << endl;
				return 0;
			}
			a[i] = v2.back();
			sum1--;
			sum2++;
			v2.pop_back();
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) if (a[i] != b[i]) ans++;
	printf("%d\n", ans);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}