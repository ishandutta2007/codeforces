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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	n *= 2;
	int ans = 0;
	for (int i = 0; i <= b; i++)
	{
		for (int j = 0; j <= c && i * 2 + j * 4 <= n; j++)
		{
			int r = n - i * 2 - j * 4;
			if (a >= r) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}