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
ifstream fin("aa.txt");
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
int dp[1050];
int d[1050];
int s[1050];
int res[1050];
int main()
{
	int m,k;
	cin >> m >> k;
	MEM(d,0);
	MEM(s,0);
	MEM(dp,0x1f);
	MEM(res,0);
	dp[0] = 0;
	for(int i = 1; i <= m; i++)
	{
		cin >> d[i];
		d[i]+=d[i-1];
	}
	for(int i = 0; i < m; i++)
	{
		cin >> s[i];
	}
	res[0] = s[0];
	for(int i = 0; i < m; i++)
	{
		int r = res[i];
		int pt = 0;
		for(int j = i+1; j <= m; j++)
		{
			
			int t = (d[j]-d[i]-r)/s[i];
			if(t * s[i] < d[j]-d[i]-r) t ++;
			t = MAX(t,pt);
			pt = t;
			if(dp[j] > dp[i]+d[j] - d[i] + t*k)
			{
				dp[j] = MIN(dp[j],dp[i]+d[j] - d[i] + t*k );
				res[j] = t*s[i] - d[j] + d[i] + r + s[j];
			}
			else if(dp[j] == dp[i]+d[j] - d[i] + t*k)
			{
				res[j] = MAX(res[j],t*s[i] - d[j] + d[i] + r + s[j]);
			}
			r += s[j];
		}
	}
	cout << dp[m] << endl;
			

	return 0;
}