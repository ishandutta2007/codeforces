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
const int N = 1e3+10;
LL dp[N][N];
const LL INF = 1000000007;
int main()
{
	//freopen("input.txt", "r", stdin);
	int a[N];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		
			dp[i][i + 1] = 2;
			for (int j = a[i]; j < i; j++)
			{
				dp[i][i + 1] += dp[j][j + 1];
				dp[i][i + 1] %= INF;
			}
			ans += dp[i][i + 1];
			ans %= INF;
	}
	cout << ans << endl;
	return 0;
}