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
const int N = 2e5 + 10;

int h[N];
int w[N];
int lmax[N];
int rmax[N];
int sum = 0;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	lmax[0] = 0;
	rmax[n + 1] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> h[i];
		sum += w[i];
		lmax[i] = max(lmax[i - 1], h[i]);
	}
	for (int i = n; i > 0; i--)
	{
		rmax[i] = max(rmax[i + 1], h[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << max(rmax[i + 1], lmax[i - 1])*(sum - w[i]) << ' ';
	}
	return 0;
}