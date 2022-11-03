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
typedef long long LLL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	vector<int> v = { 1,2,3,4,5,6,7,8,9 };
	map<int, int> mc;
	do
	{
		int sum = 0;
		int cur = 0;
		for (auto& x : v)
		{
			sum += x;
			cur = cur * 10 + x;
			if (!mc.count(sum)) mc[sum] = cur;
			mc[sum] = min(mc[sum], cur);
		}
	} while (next_permutation(v.begin(), v.end()));
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", mc[n]);
	}
	return 0;
}