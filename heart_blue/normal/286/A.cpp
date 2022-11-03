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
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n %4 == 2 || n %4 == 3)
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i = 2; i <= n; i+=2)
	{
		if (a[i]) continue;
		int o = 4;
		int cur = i;
		a[cur] = n-i+2;
		while (o--)
		{
			a[a[cur]] = n - cur + 1;
			cur = a[cur];
		}
	}
	if (n & 1) a[n / 2 + 1] = n / 2 + 1;
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	return 0;
}