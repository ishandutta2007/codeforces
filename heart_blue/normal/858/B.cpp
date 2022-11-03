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
const int N = 1e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	MEM(a, 0);
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x] = y;
	}
	if (a[n])
	{
		cout << a[n] << endl;
		return 0;
	}
	map<int, int> mc;
	for (int i = 1; i < N; i++)
	{
		int flag = 1;
		for (int j = 1; j < N; j++)
		{
			if (!a[j]) continue;
			if (a[j] != (j - 1) / i + 1)
			{
				flag = 0;
				break;
			}
		}
		if (flag) mc[(n - 1) / i + 1] = 1;
	}
	if (mc.size() > 1) puts("-1");
	else cout << mc.begin()->first << endl;
	return 0;
}