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
LL sum(int n)
{
	return 1LL * n * (n - 1) / 2;
}
vector<LL> v;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i <= 30; i++)
	{
		LL o = 1LL << i;
		o--;
		v.push_back(o * o - sum(o));
	}
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		LL x;
		cin >> x;
		int ans = 0;
		for (auto& y : v)
		{
			if (x >= y) x -= y, ans++;
			else break;
		}
		printf("%d\n", ans);
	}
	return 0;
}