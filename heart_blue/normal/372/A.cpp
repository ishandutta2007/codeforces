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
const int N = 1e6;
int a[N];
int n;
int getans(int l, int r)
{
	int ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (mid - 1 >= n - mid)
		{
			r = mid - 1;
			continue;
		}
		int k = 0;
		int flag = 1;
		while (k < mid)
		{
			if (a[k] * 2>a[n - mid + k])
			{
				flag = 0;
				break;
			}
			k++;
		}
		if (flag) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return n - ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	cout << getans(0, n - 1) << endl;
	return 0;
}