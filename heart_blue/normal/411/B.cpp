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

const int N = 101;
int a[N][N];
int flag[N];
int fail[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int j = 1; j <= m; j++)
	{
		MEM(flag, 0);
		for (int i = 1; i <= n; i++)
		{
			if (!fail[i]) flag[a[i][j]]++;
			else flag[a[i][fail[i]]] = 2;
		}
		flag[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!fail[i] && flag[a[i][j]] > 1)
			{
				fail[i] = j;
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << fail[i] << endl;
	return 0;
}