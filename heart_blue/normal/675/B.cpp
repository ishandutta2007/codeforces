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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	LL cnt = 0;
	for (int x = 1; x <= n; x++)
	{
		int y = x + a - d;
		if (y <= 0 || y > n) continue;
		int z = x + c - b;
		if (z <= 0 || z > n) continue;
		int w = y + c - b;
		if (w <= 0 || w > n) continue;
		cnt++;
	}
	cout << n*cnt << endl;
	return 0;
}