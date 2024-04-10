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
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))
#define ABS(x) ((x) > 0 ? (x):(-x))
LL dp[1 << 18][101];
LL fact[18];
int main()
{
	//freopen("input.txt", "r", stdin);
	MEM(dp, 0);
	dp[0][0] = 1;
	LL n, m;
	cin >> n >> m;
	vector<int> v;
	int t = 0;
	while (n)
	{
		v.push_back(n % 10);
		n /= 10;
		t++;
	}
	sort(v.begin(), v.end());
	vector<int> mod(t);
	mod[0] = 1 % m;
	fact[0] = 1;
	for (int i = 1; i < 18; i++) fact[i] = i*fact[i - 1];
	for (int i = 1; i < t; i++)
	{
		mod[i] = mod[i - 1] * 10 % m;
	}
	reverse(mod.begin(), mod.end());
	for (int i = 0; i < (1 << t)-1; i++)
	{
		int c = 0;
		int k = i;
		while (k)
		{
			c+=k&1;
			k >>= 1;
		}
		for (int j = 0; j < t; j++)
		{
			if (j == 0 && v[c] == 0) continue;
			if (((1 << j)&i) == 0)
			{
				int s = (1 << j) | i;
				for (int x = 0; x < m; x++)
				{
					dp[s][(x + v[c] * mod[j]) % m] += dp[i][x];
				}

			}
		}
	}
	LL ans = dp[(1 << t) - 1][0];
	int cnt = 1;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] != v[i - 1])
		{
			ans /= fact[cnt];
			cnt = 1;
		}
		else cnt++;
	}
	ans /= fact[cnt];
	cout << ans << endl;
	return 0;
}