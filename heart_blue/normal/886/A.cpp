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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v(6);
	int sum = 0;
	for (auto &x : v) cin >> x, sum += x;
	sort(v.begin(), v.end());
	do
	{
		if ((v[0] + v[1] + v[2]) * 2 == sum)
		{
			puts("YES");
			return 0;
		}
	} while (next_permutation(v.begin(), v.end()));
	puts("NO");
	return 0;
}