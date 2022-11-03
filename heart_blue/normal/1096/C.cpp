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
const int N = 1e3 + 10;
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i < 180; i++)
	{
		if (360 % i) continue;
		for (int j = i; j < 360 - i; j += i)
		{
			ans[j] = 360 / i;
		}
	}
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		cout << ans[n * 2] << endl;
	}
	return 0;
}