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
const int N = 4e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int minv = INF;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i + n] = a[i];
		minv = min(minv, a[i]);
	}
	n += n;
	int pre = n;
	int maxdis = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == minv)
		{
			maxdis = max(maxdis, i - pre - 1);
			pre = i;
		}
	}
	cout << (LL)n/2*minv + maxdis << endl;
	return 0;
}