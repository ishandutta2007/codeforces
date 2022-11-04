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
const int N = 5e3 + 10;
pair<int, int> check(int n)
{
	vector<int> v;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i) continue;
		while (n % i == 0) n /= i;
		v.push_back(i);
		if (v.size() > 1) break;
	}
	if (n > 1) v.push_back(n);
	if (v.size() == 1) puts("NO"), exit(0);
	return make_pair(v[0], v[1]);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int a, b;
	tie(a, b) = check(n);
	if (a > b) swap(a, b);
	for (int i = 1; i <= n; i++)
	{
		if ((n - 1 - b * i) % a == 0)
		{
			puts("YES");
			puts("2");
			printf("%d %d\n", i, n / b);
			printf("%d %d\n", (n - 1 - b * i) / a, n / a);
			return 0;
		}
	}
	return 0;
}