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
const int N = 2e3;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);

	int n, sum;
	cin >> n >> sum;
	int t = 0;
	int c1, c2;
	c1 = c2 = 0;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i], c1 += a[i], c2 += b[i];
	if (c1 > sum || sum > c2)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	sum -= c1;
	for (int i = 0; i < n; i++)
	{
		cout << min(b[i], sum + a[i]) << ' ';
		sum -= min(b[i], sum + a[i]) - a[i];
	}
	return 0;
}