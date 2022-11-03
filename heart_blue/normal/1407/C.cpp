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
int ask(int i, int j)
{
	cout << "? " << i << " " << j << endl;
	int ret;
	cin >> ret;
	return ret;
}
int flag[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int cur = 1;
	for (int i = 2; i <= n; i++)
	{
		int x = ask(cur, i);
		int y = ask(i, cur);
		if (x < y)
		{
			ans[i] = y;
			flag[y] = 1;
		}
		else
		{
			ans[cur] = x;
			flag[x] = 1;
			cur = i;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == 0)
		{
			ans[cur] = i;
		}
	}
	cout << "!";
	for (int i = 1; i <= n; i++)
	{
		cout << " " << ans[i];
	}
	cout << endl;
	return 0;
}