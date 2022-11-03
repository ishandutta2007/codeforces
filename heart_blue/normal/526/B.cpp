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
const int N = 1e4 + 10;
int a[N];
int maxv[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 2; i < (2 << n); i++)
	{
		cin >> a[i];
	}
	MEM(maxv, 0);
	for (int i = (2 << n) - 1; i > 1; i--)
	{
		maxv[i] += a[i];
		maxv[i / 2] = max(maxv[i / 2], maxv[i]);
	}
	int ans = 0;
	for (int i = 2; i < (2 << n); i += 2)
	{
		ans += abs(maxv[i] - maxv[i ^ 1]);
	}
	cout << ans << endl;
	return 0;
}