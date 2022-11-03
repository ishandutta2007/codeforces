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
int flag[10];
bool check(int x)
{
	while (x)
	{
		if (flag[x % 10]) return true;
		x /= 10;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int o = n;
	MEM(flag, 0);
	while(o)
	{
		flag[o % 10] = 1;
		o /= 10;
	}
	int ans = 0;
	for (int i = 1; i * i <= n; i++)
	{
		if (n%i != 0) continue;
		if (check(i)) ans++;
		if (check(n / i) && i != n / i) ans++;
	}
	cout << ans << endl;
	return 0;
}