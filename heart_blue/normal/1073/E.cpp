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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const LL MOD = 998244353;
const int N = 2e5 + 10;
int a[20];
int cnt[N];
pair<LL, LL> dp[20][N];//  
LL p10[N];
int k;
void init()
{
	cnt[0] = 0;
	for (int i = 1; i < N; i++)
	{
		cnt[i] = cnt[i >> 1] + (i & 1);
	}
	p10[0] = 1;
	for (int i = 1; i < N; i++)
	{
		p10[i] = p10[i - 1] * 10 % MOD;
	}
}
pair<LL, LL> dfs(int pos, int state, bool lead/**/, bool limit/**/)//  
{
	if (lead) state = 0;
	if (cnt[state] > k) return { 0LL,0LL };
	//0pos==-1  
	if (pos == -1) return { state ? 1LL : 0LL,0LL };/*1pos1 */
	//()  
	if (!limit && !lead && dp[pos][state].first != -1) return dp[pos][state];
	/**/
	int up = limit ? a[pos] : 9;//limitup;213  
	pair<LL, LL> ans;
	//  
	for (int i = 0; i <= up; i++)//ans  
	{
		auto tmp = dfs(pos - 1, (state | (1 << i)), lead && i == 0, limit && i == a[pos]);//  
		ans.first = (ans.first + tmp.first) % MOD;
		ans.second = (ans.second + tmp.second + i * p10[pos] % MOD*tmp.first%MOD) % MOD;
	}
	//  
	if (!limit && !lead) dp[pos][state] = ans;
	/*leadlead*/
	return ans;
}
LL solve(LL x)
{
	if (x == 0) return 0;
	int pos = 0;
	while (x)//  
	{
		a[pos++] = x % 10;//[0,pos),  
		x /= 10;
	}
	return dfs(pos - 1, 0, true, true).second;//0  
}
int main()
{
	MEM(dp, -1);
	LL L, R;
	init();
	scanf("%lld%lld%d", &L, &R, &k);
	LL ans = solve(R) - solve(L - 1);
	if (ans < 0) ans += MOD;
	printf("%lld\n", ans);
}