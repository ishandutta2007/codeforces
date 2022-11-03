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
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int h, m;
	int n;
	scanf("%d", &n);
	scanf("%d:%d", &h, &m);
	if (m >= 60) m %= 10;
	if (n == 12)
	{
		if (h % 10 == 0) h = h % 10 + 10;
		if (h > 12) h = h % 10;
	}
	if (n == 24)
	{
		if (h >= 24) h %= 10;
	}
	printf("%02d:%02d\n", h, m);
	return 0;
}