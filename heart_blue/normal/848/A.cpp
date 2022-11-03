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
const int N = 1e3 + 10;
int sum[N];
int flag[N*N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(sum, 0);
	MEM(flag, 0);
	sum[1] = 0;
	flag[0] = 1;
	for (int i = 2; i < N; i++)
	{
		sum[i] = i - 1 + sum[i - 1];
		flag[sum[i]] = i;
	}
	int n;
	cin >> n;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; sum[i] + sum[j] <= n; j++)
		{
			if (flag[n - sum[i] - sum[j]])
			{
				int x = i;
				int y = j;
				int z = flag[n - sum[i] - sum[j]];
				cout << string(x, 'a');
				cout << string(y, 'b');
				cout << string(z, 'c');
				return 0;
			}
		}
	}
	return 0;
}