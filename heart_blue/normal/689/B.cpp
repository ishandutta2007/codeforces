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
const int N = 2e6 + 10;
int flag[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(flag, 0);
	int n;
	cin >> n;
	list<int> l;
	l.push_back(1);
	flag[1] = 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	while (!l.empty())
	{
		int x = l.front();
		l.pop_front();
		int y = a[x];
		if (!flag[y])
		{
			flag[y] = flag[x] + 1;
			l.push_back(y);
		}
		if (x > 1 && !flag[x - 1])
		{
			flag[x - 1] = flag[x] + 1;
			l.push_back(x - 1);
		}
		if (x < n && !flag[x + 1])
		{
			flag[x + 1] = flag[x] + 1;
			l.push_back(x + 1);
		}	
	}
	for (int i = 1; i <= n; i++)
	{
		cout << flag[i] - 1 << " \n"[i == n];
	}
	return 0;
}