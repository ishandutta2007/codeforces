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
const int N = 2e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	map<int, int> mc;
	while (n--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		mc[a]++;
		mc[b]--;
	}
	int ans = 0, key = 0;
	int sum = 0;
	for (auto& p : mc)
	{
		sum += p.second;
		if (sum > ans)
		{
			ans = sum;
			key = p.first;
		}
	}
	printf("%d %d\n", key, ans);
	return 0;
}