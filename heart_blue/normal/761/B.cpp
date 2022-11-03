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
#include <cassert>
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	int flag = 0;
	for (int k = 0; k < n; k++)
	{
		int o = (a[0] - b[k] + m) % m;
		flag = 1;
		for (int i = 0; i < n; i++)
		{
			if ((a[i] - b[(i+k)%n] + m) % m != o)
			{
				flag = 0;
				break;
			}
		}
		if (flag) break;
	}
	if (flag) puts("YES");
	else puts("NO");
	return 0;
}