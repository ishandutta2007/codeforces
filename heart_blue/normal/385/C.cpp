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
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))
const int N = 1e7 + 1;
int a[N];
int cnt[N];
int ans[N];
void init(int n)
{
	MEM(a, 0);
	for (int i = 2; i <= n; i++)
	{
		if (a[i]) continue;
		for (int j = i; j <= n; j += i)
		{
			a[j] = 1;
			ans[i] += cnt[j];
		}
	}
	for (int i = 2; i <= n; i++)
	{
		ans[i] += ans[i - 1];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	int x;
	int maxv = 0;
	while (n--)
	{
		cin >> x;
		maxv = max(maxv, x);
		cnt[x] ++;
	}
	init(maxv);
	int m;
	int l, r;
	cin >> m;
	while (m--)
	{
		cin >> l >> r;
		if (l > maxv)
		{
			cout << 0 << endl;
			continue;
		}
		r = MIN(maxv, r);
		cout << ans[r] - ans[l - 1] << endl;
	}
	return 0;
}