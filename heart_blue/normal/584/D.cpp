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
const int N = 1e6 + 10;

int a[N];
int p[N];
int k = 0;
void init()
{
	MEM(a, 0);
	a[0] = a[1] = 1;
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		for (int j = i + i; j < N; j += i) a[j] = 1;
		p[k++] = i;
	}
}

bool isPrime(int n)
{
	if (n < N) return a[n] == 0;
	for (int i = 0; i < k; i++)
	{
		if (LL(p[i])*p[i] >  n) break;
		if (n%p[i] == 0) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	init();
	cin >> n;
	if (isPrime(n))
	{
		cout << 1 << endl;
		cout << n << endl;
		return 0;
	}
	if (isPrime(n - 2))
	{
		cout << 2 << endl;
		cout << 2 << ' ' << n - 2 << endl;
		return 0;
	}
	for (int i = n; i > 0; i -= 2)
	{
		if (isPrime(i))
		{
			int o = n - i;
			for (int j = 0; j < k; j++)
			{
				if (isPrime(o - p[j]))
				{
					cout << 3 << endl;
					cout << i << ' ' << p[j] << ' ' << o - p[j] << endl;
					break;
				}
			}
			break;
		}
	}
	return 0;
}