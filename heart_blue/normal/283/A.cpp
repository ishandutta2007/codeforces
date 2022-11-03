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
LL a[N];
LL b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	LL sum = 0;
	int n = 1;
	cin >> q;
	a[0] = b[0] = 0;
	while (q--)
	{
		int op, x, y;
		cin >> op;
		
		if (op == 1)
		{
			cin >> x >> y;
			x = min(x, n) - 1;
			b[x] += y;
			sum += (x + 1)*y;
		}
		if (op == 2)
		{
			cin >> x;
			a[n] = x;
			b[n] = 0;
			sum += x;
			n++;
		}
		if (op == 3)
		{
			n--;
			sum -= b[n] + a[n];
			b[n - 1] += b[n];
		}
		printf("%.15f\n", sum*1.0 / n);
	}
	return 0;
}