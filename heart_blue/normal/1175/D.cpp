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
const int N = 3e5 + 10;
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<LL> v;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &sum[i]);
	}
	for (int i = n; i >= 1; i--) sum[i] += sum[i + 1];
	sort(sum + 2, sum + n + 1);
	reverse(sum + 2, sum + n + 1);
	LL ans = 0;
	for (int i = 1; i <= k; i++)
		ans += sum[i];
	printf("%lld\n", ans);
	return 0;

}