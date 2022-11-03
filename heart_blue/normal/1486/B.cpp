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
#include <random>
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
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		vector<int> v1(n), v2(n);
		for (int i = 0; i < n; i++)
			cin >> v1[i] >> v2[i];
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int l1 = v1[(n - 1) / 2], r1 = v1[n / 2];
		int l2 = v2[(n - 1) / 2], r2 = v2[n / 2];
		printf("%lld\n", 1LL * (r1 - l1 + 1) * (r2 - l2 + 1));
	}
	return 0;
}