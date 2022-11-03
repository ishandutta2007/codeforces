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
const int N = 5000 + 10;
int a[N];
int dfs(int l, int r)
{
	int minv = 1e9 + 10;
	int key = -1;
	int ans = r - l + 1;
	for (int i = l; i <= r; i++)
	{
		if (minv > a[i]) minv = a[i], key = i;
	}
	if (ans <= a[key]) return ans;
	for (int i = l; i <= r; i++) a[i] -= minv;
	
	int sum = minv;
	int s = l;
	int t;
	while (s <= r)
	{
		if (a[s])
		{
			for ( t = s; t <= r; t++)
			{
				if (!a[t]) break;
			}
			sum += dfs(s, t - 1);
			if (sum >= ans) return ans;
			s = t - 1;
		}
		s++;
	}
	return min(sum, ans);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << dfs(1, n) << endl;
	return 0;
}