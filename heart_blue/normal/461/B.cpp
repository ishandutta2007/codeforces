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
const int N = 1e5+10;
const int M = N;
vector<int> v[N];
int c[N];
LL dp[N][2];
LL powmod(LL a)
{
	int b = INF - 2;
	LL ans = 1;
	while (b)
	{
		if (b & 1) ans *= a;
		a *= a;
		a %= INF;
		ans %= INF;
		b >>= 1;
	}
	return ans;
}
void dfs(int x, int p)
{
	dp[x][0] = 1;
	dp[x][1] = 0;
	for (int i = 0; i < v[x].size(); i++)
	{
		if (v[x][i] == p) continue;
		dfs(v[x][i], x);
	}
	for (int i = 0; i < v[x].size(); i++)
	{
		if (v[x][i] == p) continue;
		int y = v[x][i];
		dp[x][1] *= dp[y][0];
		dp[x][1] %= INF;
		dp[x][1] += dp[x][0] * dp[y][1];
		dp[x][1] %= INF;
		dp[x][0] *= dp[y][0];
		dp[x][0] %= INF;
	}
	if (c[x] == 1)
		dp[x][1] = dp[x][0];
	else
		dp[x][0] += dp[x][1];
	dp[x][1] %= INF;
	dp[x][0] %= INF;
	
}
int main()
{
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x;
		cin >> x;
		v[i].push_back(x);
		v[x].push_back(i);
	}
	for (int i = 0; i < n; i++) cin >> c[i];
	dfs(0, -1);
	cout << dp[0][1] << endl;
	return 0;

}