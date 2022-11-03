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
#define ABS(x) ((x) > 0 ? (x):(-x))
int a[4010];
int main()
{
	//freopen("input.txt", "r", stdin);
	MEM(a, 0);
	int n, k;
	int ans1, ans2;
	ans1 = ans2 = 0;
	cin >> n >> k;
	while (k--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int x, y;
			cin >> x >> y;
			a[x] = a[y] = 1;
		}
		else
		{
			int x;
			cin >> x;
			a[x] = 1;
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] == 0) ans1++;
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] == 0) i++, ans2++;
	}
	cout << ans2 << ' ' << ans1 << endl;
	return 0;
}