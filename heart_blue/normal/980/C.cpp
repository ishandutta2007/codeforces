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
const int N = 2e5 + 10;
int a[N];
int belong[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	MEM(belong, -1);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (belong[a[i]] != -1)
		{
			cout << belong[a[i]] << ' ';
			continue;
		}
		if (a[i] - k + 1 <= 0)
		{
			for (int j = 0; j <= a[i]; j++) belong[j] = 0;
		}
		else
		{
			int o = a[i] - k;
			if (belong[o] == -1)
			{
				for (int j = o + 1; j <= a[i]; j++) belong[j] = o + 1;
			}
			else
			{
				int key = belong[o];
				while (belong[o] == key) o++;
				for (int j = o; j <= a[i]; j++) belong[j] = o;
			}
		}
		cout << belong[a[i]] << ' ';
	}

	return 0;
}