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
#define MP(x,y) make_pair(x,y) 
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))
string str;
const int N = 2e4 + 10;
int a[N][11];
int b[11];
int main()
{
	//freopen("input.txt", "r", stdin);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			a[i][j] = -a[i][j];
		}
	}
	int x, y;
	while (k--)
	{
		scanf("%d%d", &x, &y);
		a[x][y] --;
		b[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		int ans = 0;
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] < 0) ans +=  a[i][j] +1+ b[j];
		}
		if (i > 1) putchar(' ');
		printf("%d", ans);
	}
	puts("");
	return 0;
}