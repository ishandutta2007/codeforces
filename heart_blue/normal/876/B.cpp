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
const int N = 1e5 + 10;
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, m;
	cin >> n >> k >> m;
	map<int, int> mc;
	while (n--)
	{
		int x;
		cin >> x;
		mc[x%m]++;
		v[x%m].push_back(x);
		if (mc[x%m] == k)
		{
			puts("Yes");
			for (auto &y : v[x%m]) printf("%d ", y);
			return 0;
		}
	}
	puts("No");
	return 0;
}