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
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	a[0][0] = 1;
	for (int o = 1; o <= 9; o++)
	{
		int k = 1 << (o - 1);
		for (int i = 0; i < (1 << o); i++)
		{
			for (int j = 0; j < (1 << o); j++)
			{
				a[i][j] = a[i%k][j%k];
				if (i >= k && j >= k) a[i][j] ^= 1;
			}
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < (1 << n); j++)
		{
			if (a[i][j]) putchar('*');
			else putchar('+');
		}
		puts("");
	}
	return 0;
}