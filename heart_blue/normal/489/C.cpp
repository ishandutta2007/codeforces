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
const int N = 1e3;
void dfs1(int cur, int len, int sum)
{
	int t;
	if (cur == len)
	{
		cout << sum << ' ';
		return;
	}
	for (int i = (cur == 1 ? 1 : 0); i < 10; i++)
	{
		if ((len - cur) * 9 + i >= sum&&sum-i >= 0)
		{

			cout << i;
			t = i;
			break;
		}
	}
	dfs1(cur + 1, len, sum - t);
}

void dfs2(int cur, int len, int sum)
{
	int t;
	if (cur == len)
	{
		cout << sum;
		return;
	}
	for (int i = 9; i >= (cur == 1 ? 1 : 0); i--)
	{
		if ((len - cur) * 9 >= sum-i && sum-i >= 0)
		{
			cout << i;
			t = i;
			break;
		}
	}
	dfs2(cur + 1, len, sum - t);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int len, sum;
	cin >> len >> sum;
	if (sum == 0)
	{
		cout << (len == 1 ? "0 0" : "-1 -1") << endl;
		return 0;
	}
	if (len * 9 < sum)
	{
		cout << "-1 -1" << endl;
		return 0;
	}
	dfs1(1, len, sum);
	dfs2(1, len, sum);
	return 0;
}