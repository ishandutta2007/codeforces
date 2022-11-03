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

int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	int l, r, mid;
	l = r = mid = 0;
	int ans = n;
	int cnt = 0;
	while (l < n && r < n)
	{
		if (str[l] == '1')
		{
			l++;
			continue;
		}
		if (str[r] == '1')
		{
			r++;
			continue;
		}
		if (cnt < k + 1)
		{
			
			cnt++;
			if (cnt == k + 1)
			{
				mid = max(mid, l);
				mid = min(mid, r);
				while (mid <= r)
				{
					while (mid <= r && str[mid] == '1') mid++;
					if (mid > r) break;
					ans = min(ans, max(mid - l, r - mid));
					if (mid - l > r - mid)
					{
						break;
					}
					mid++;
				}
				l++;
				cnt--;
			}
			r++;
		}
		

	}
	cout << ans << endl;
	return 0;
}