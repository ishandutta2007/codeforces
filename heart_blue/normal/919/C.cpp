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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
int a[N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	MEM(a, 0);
	int tot = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		int o = 0;
		for (int j = 0; j < m; j++)
		{
			if (str[j] == '.') o++, a[j]++;
			else o = 0, a[j] = 0;
			tot += o >= k;
			tot += a[j] >= k;
		}
	}
	if (k == 1) tot /= 2;
	cout << tot << endl;
	return 0;
}