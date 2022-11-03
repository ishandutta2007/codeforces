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
const int N = 1e5 + 10;
int p[N];
int t[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, c;
	cin >> n >> c;
	int sum1 = 0, sum2 = 0;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) cin >> t[i];
	int cost = 0;
	for (int i = 1; i <= n; i++)
	{
		cost += t[i];
		sum1 += max(0, p[i] - c*cost);
	}
	cost = 0;
	for (int i = n; i >= 1; i--)
	{
		cost += t[i];
		sum2 += max(0, p[i] - c*cost);
	}
	if (sum1 > sum2) puts("Limak");
	else if (sum1 == sum2) puts("Tie");
	else puts("Radewoosh");
	return 0;
}