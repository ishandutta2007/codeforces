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
const int N = 3e5 + 10;
char str[N * 2];
int sum[N];
int layer[N];
int key[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", str + 1);
	if (count(str + 1, str + n + 1, '(') * 2 != n)
	{
		puts("0");
		puts("1 1");
		return 0;
	}
	pair<int, int> minv = { 0,0 };
	for (int i = 1; i <= n; i++)
	{
		str[i + n] = str[i];
		sum[i] += sum[i - 1] + (str[i] == '(' ? 1 : -1);
		minv = min(minv, make_pair(sum[i], i));
	}
	int ptr = minv.second;
	int o = 0;
	vector<int> v;
	MEM(sum, 0);
	int cnt1 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (str[i + ptr] == '(')
		{
			o++, v.push_back(i);
			layer[i] = o;
			if (o == 1) cnt1++;
		}
		else
		{
			o--;
			key[v.back()] = i;
			v.pop_back();
			if (!v.empty()) sum[v.back()]++;
		}
	}
	tuple<int, int, int> ans = { cnt1,1,1 };
	for (int i = 1; i <= n; i++)
	{
		if (layer[i] == 0) continue;
		if (layer[i] == 1)
		{
			ans = max(ans, { sum[i] + 1, i, key[i] });
		}
		if (layer[i] == 2)
		{
			ans = max(ans, { cnt1 + 1 + sum[i],i,key[i] });
		}
	}
	int res, l, r;
	tie(res, l, r) = ans;
	l += ptr;
	r += ptr;
	if (l > n) l -= n;
	if (r > n) r -= n;
	printf("%d\n%d %d\n", res, l, r);
	return 0;
}