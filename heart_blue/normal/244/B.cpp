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
const int N = 1e6 + 10;
int n;
map<int, int> mc;
int solve(int x, int y)
{
	queue<LL> q;
	if (x) q.push(x);
	q.push(y);
	int ret = 0;
	while (!q.empty())
	{
		LL o = q.front();
		q.pop();
		if (o > n) continue;
		mc[o] = 1;
		q.push(o * 10 + x);
		q.push(o * 10 + y);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			solve(i, j);
		}
	}
	cout << mc.size() << endl;
	return 0;
}