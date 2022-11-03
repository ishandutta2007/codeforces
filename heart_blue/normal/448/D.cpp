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
LL n, m;
LL k;

bool check(LL x)
{
	LL sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += min(x / i, m);
	}
	return sum >= k;
}

LL bs(LL l, LL r)
{
	LL ret = -1;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		if (check(mid)) ret = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> n >> m >> k;
	cout << bs(1, n*m) << endl;
	return 0;
}