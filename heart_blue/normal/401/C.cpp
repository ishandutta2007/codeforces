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
	int n, m;
	cin >> n >> m;
	if (n <=1 && m <= 2)
	{
		while (n--) cout << 0;
		while (m--) cout << 1;
	}
	else if (n > m + 1 || m > 2 * n + 2)
	{
		cout << -1;
	}
	else
	{
		int st = 0;
		if (n >= m)
		{
			int t = n + m;
			st = 0;
			while (t--)
			{
				cout << st;
				st ^= 1;
			}
		}
		else
		{
			m-=n;
			while (n--)
			{
				if (m-- && m >= 0) cout << 1;
				cout << 10;
			}
			if (m < 0) m = 0;
			while (m--) cout << 1;
		}

	}
	cout << endl;
	return 0;
}