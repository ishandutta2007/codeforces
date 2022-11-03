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
const long long INF = 1e9 + 7;
const int N = 1 << 20;
int a[1 << 10][1 << 10];
int main()
{
	//freopen("input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	if (k * 2 >= n)
	{
		cout << -1 << endl;
		return 0;
	}
	MEM(a, 0);
	int cnt = 0;

	cout << n*k << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			int t = i + j;
			if (t > n) t -= n;
			if (a[i][t]) continue;
			a[i][t] = a[t][i] = 1;
			printf("%d %d\n", i, t);
		}
		for (int j = 1; j <= k; j++)
		{
			int t = i - j;
			if (t <= 0) t += n;
			if (a[i][t]) continue;
			a[i][t] = a[t][i] = 1;
			printf("%d %d\n", t, i);
		}
	}
	return 0;
}