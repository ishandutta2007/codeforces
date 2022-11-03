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
const LL INF = 1e9+7;
const int N = 1e3+10;
const int M = 1e4;
int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	int n, k, d;
	cin >> n >> k >> d;
	int flag = 1;
	MEM(a,0);
	if(n == 1)
	{
		while(d--) cout << 1 << endl;
		return 0;
	}
	for(int i = 1; i <= d; i++) a[1][i] = 1;
	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j <= d; j++) a[i][j] = a[i-1][j];
		a[i][d] ++;
		for(int j = d; j > 0; j--)
		{
			if(a[i][j] > k) a[i][j] = 1, a[i][j-1] ++;
			else break;
		}
		if(a[i][0] == 1)
		{
			flag = 0;
			break;
		}
	}
	if(!flag)
	{
		cout << -1 << endl;
		return 0;
	}
	for(int j = 1; j <= d; j++)
	{
		for(int i = 1; i <= n; i++)
		{
			if(i > 1) cout << ' ';
			cout << a[i][j];
		}
		cout << '\n';
	}
	return 0;
}