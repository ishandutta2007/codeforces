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
LL dp[2001][2001];
const int INF = 1000000007;
int main()
{
	//freopen("input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) dp[1][i] = 1;
	for (int i = 1; i < k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int t = 1; t*j <= n; t++)
			{
				dp[i + 1][t*j] += dp[i][j];
				dp[i + 1][t*j] %= INF;
			}
		}
	}
	LL sum = 0;
	for (int i = 1; i <= n; i++) sum = (sum + dp[k][i]) % INF;
	cout << sum << endl;
	return 0;
}