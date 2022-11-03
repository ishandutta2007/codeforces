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
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x;
	scanf("%d%d", &n, &x);
	flag[x] = 1;
	vector<int> ans;
	int pre = 0;
	for (int i = 1; i < (1 << n); i++)
	{
		if (flag[i]) continue;
		ans.emplace_back(i ^ pre);
		pre = i;
		flag[i] = flag[i ^ x] = 1;
	}
	printf("%d\n", ans.size());
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}