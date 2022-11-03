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
class Friend
{
public:
	LL x, k, m;
	bool operator < (Friend &f)
	{
		return k < f.k;
	}
};
LL dp[1 << 20];
int main()
{
	//freopen("input.txt", "r", stdin);
	LL n, m, b;
	cin >> n >> m >> b;
	vector<Friend> vf(n);
	for (int i = 0; i < n; i++)
	{
		int mm;
		cin >> vf[i].x >> vf[i].k >> mm;
		vf[i].m = 0;
		while (mm--)
		{
			int t;
			cin >> t;
			vf[i].m |= 1 << (t - 1);
		}
	}
	sort(vf.begin(), vf.end());
	MEM(dp, 0x7f);
	LL INF = dp[0];
	LL ans = INF;
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 1 << m; j++)
		{
			if (dp[j] < INF)
			{
				int t = j | vf[i].m;
				dp[t] = MIN(dp[t], dp[j] + vf[i].x);
			}
		}
		if (dp[(1 << m) - 1] < INF)
			ans = MIN(dp[(1 << m) - 1] + b*vf[i].k, ans);
	}
	if (ans < INF) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}