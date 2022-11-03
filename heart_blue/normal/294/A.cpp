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
const LL INF = 1e9 + 1;
const int N = 1e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt","r",stdin);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int m;
	cin >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		a[x - 1] += y - 1;
		a[x + 1] += a[x] - y;
		a[x] = 0;
	}
	for (int i = 1; i <= n; i++) cout << a[i] << endl;
	return 0;
}