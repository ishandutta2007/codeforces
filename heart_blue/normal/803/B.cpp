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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0x3f);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x == 0) a[i] = 0;
		a[i] = min(a[i], a[i - 1] + 1);
	}
	for (int i = n; i > 0; i--)
	{
		a[i] = min(a[i], a[i + 1] + 1);
	}
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	return 0;
}