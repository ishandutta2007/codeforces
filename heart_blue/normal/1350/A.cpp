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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int check(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i) continue;
		return i;
	}
	return n;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, k;
		cin >> n >> k;
		while (k)
		{
			int x = check(n);
			if (x == 2)
			{
				n += k * 2;
				k = 0;
			}
			else
			{
				n += x;
				k--;
			}
		}
		cout << n << endl;

	}
	return 0;
}