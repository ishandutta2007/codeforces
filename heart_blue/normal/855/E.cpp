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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[70];
LL dp[11][70][1200];//  
LL dfs(int pos, int state, bool lead/**/, bool limit/**/, int b)//  
{
	//0pos==-1  
	if (pos == -1) return state == 0;/*1pos1 */
						//()  
	if (!limit && !lead && dp[b][pos][state] != -1) return dp[b][pos][state];
	/**/
	int up = limit ? a[pos] : b - 1;//limitup;213  
	LL ans = 0;
	//  
	for (int i = 0; i <= up; i++)//ans  
	{
		ans += dfs(pos - 1, (lead && i == 0) ? 0 : (state ^ (1 << i)), lead && i == 0, limit && i == a[pos], b); //  																	   62*/
	}
	//  
	if (!limit && !lead) dp[b][pos][state] = ans;
	/*leadlead*/
	return ans;
}
LL solve(LL x, int b)
{
	int pos = 0;
	while (x)//  
	{
		a[pos++] = x % b;//[0,pos),  
		x /= b;
	}
	return dfs(pos - 1/**/, 0, true, true, b);//0  
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	MEM(dp, -1);
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL l, r, b;
		scanf("%lld%lld%lld", &b, &l, &r);
		printf("%lld\n", solve(r, b) - solve(l - 1, b));
	}
	return 0;
}