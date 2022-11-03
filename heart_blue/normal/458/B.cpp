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
const int M = 1e4;

int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;
	LL sum1 = 0;
	LL sum2 = 0;
	for (int i = 0; i < n; i++) cin >> a[i], sum1 += a[i];
	for (int i = 0; i < m; i++) cin >> b[i], sum2 += b[i];
	sort(a, a + n);
	sort(b, b + m);
	if (a[n-1] < b[m-1])
	{
		for (int i = max(n, m); i >= 0; i--) swap(a[i], b[i]);
		swap(n, m);
		swap(sum1, sum2);
	}
	if (a[n - 1] == b[m - 1])
	{
		if (sum1 < sum2)
		{
			for (int i = max(n, m); i >= 0; i--) swap(a[i], b[i]);
			swap(n, m);
			swap(sum1, sum2);
		}

	}
	reverse(a, a + n);
	reverse(b, b + m);
	LL ans = sum2;
	for (int i = 1; i < n; i++)
	{
		if (a[i] >= sum2) ans += sum2;
		else ans += a[i];
	}
	cout << ans << endl;
	return 0;

}