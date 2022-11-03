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
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int a[10] = { 0 };
	int b[10] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		b[x]++;
	}
	int ans = 0;
	for (int i = 1; i <= 5; i++)
	{
		if ((a[i] + b[i]) % 2 == 1)
		{
			ans = -1;
			break;
		}
		ans += max(0, a[i] - b[i]) / 2;
	}
	cout << ans << endl;
	return 0;
}