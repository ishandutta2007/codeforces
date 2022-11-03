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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
double p[N];
double dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	double ans = 0;
	double e = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		dp[i] = (dp[i - 1] + p[i - 1])*p[i];
		ans += p[i] + 2 * dp[i];
	}
	printf("%.15f\n", ans);
	/*
	E((x+1)^2)=E(x^2)+E(2x)+1
	*/
	return 0;
}