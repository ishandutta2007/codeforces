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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const int INF = 1000000007 ;
long long a[101];
long long dp[101];
int main()
{
//	freopen("input.txt","r",stdin);
	string str;
	a[0] = 1;
	for(int i = 1; i < 101; i++)
	{
		a[i] = a[i-1]*2%INF;
	}
	cin >> str;
	int n = str.length();
	reverse(str.begin(),str.end());
	MEM(dp,0);
	dp[0] = str[0]-'0';
	for(int i = 1; i < n; i++)
	{
		if(str[i] == '0')
		{
			dp[i] = dp[i-1]*2%INF;
		}
		else
		{
			dp[i] = ((a[i]*a[i])%INF + 2*dp[i-1])%INF;
		}
	}
	cout << dp[n-1] << endl;
	return 0;

}