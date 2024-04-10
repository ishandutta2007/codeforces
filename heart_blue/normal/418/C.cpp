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
const int N = 100000;
int getX(LL t)
{
	for (int i = 1; i*i <= t; i++)
	{
		LL sum = t + i*i;
		LL c = sqrt(sum*1.0) + 1e-9;
		if (c*c == sum) return i;
	}
	return -1;
}
int main()
{
	//freopen("input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;

	if (n + m == 2)
	{
		cout << 1 << endl;
		return 0;
	}
	LL sum = n - 1;
	int t = 2;
	int x;
	LL a[101];
	LL b[101];
	while (1)
	{
		for (int i = 1; i < n; i++)
		{
			x = getX(sum);
			if (x != -1)
			{
				for (int j = 1; j < i; j++)
				{
					a[j] = t;
				}
				for (int j = i; j < n; j++)
				{
					a[j] = t - 1;
				}
				a[n] = x;
				break;
			}
			sum += t + t - 1;
		}
		if (n == 1) a[1] = x = 1;
		if (x != -1) break;
		t++;

	}

	sum = m - 1;
	t = 2;
	while (1)
	{
		for (int i = 1; i < m; i++)
		{
			x = getX(sum);
			if (x != -1)
			{
				for (int j = 1; j < i; j++)
				{
					b[j] = t;
				}
				for (int j = i; j < m; j++)
				{
					b[j] = t - 1;
				}
				b[m] = x;
				break;
			}
			sum += t + t - 1;
		}
		if (m == 1) b[1] = x = 1;
		if (x != -1) break;
		t++;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j > 1) cout << ' ';
			cout << a[i] * b[j];
		}
		cout << endl;
	}
	return 0;
}