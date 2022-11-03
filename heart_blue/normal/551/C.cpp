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
const LL INF = 1e9;
const int N = 2e5;
int n, m;
int a[N];
LL b[N];
bool check(LL x)
{
	int t = m;
	for (int i = 1; i <= n; i++) b[i] = a[i];
	for (int i = 1; i <= n; i++)
	{
		if (b[i] == 0) continue;
		if (x <= i) return false;
		int s = b[i] / (x - i);
		LL y = b[i] % (x - i);
		t -= b[i] / (x - i);
		if (t < 0) return false;
		y = (x-i-y) % (x - i);
		b[i] = 0;
		if (y && t <= 0) return false;
		if (y) t--;
		else continue;
		while (i <= n)
		{
			i++;
			y--;
			if (y <= 0) break;
			LL t = min(b[i], y);
			b[i] -= t;
			y -= t;
			if (b[i] > 0) break;
		}
		i--;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	LL r = n;
	for (int i = 1; i <= n; i++) cin >> a[i], r += a[i];
	r += r;
	LL l = 0;
	LL ans = 0;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;

}