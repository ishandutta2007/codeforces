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
const int N = 1e6 + 10;
int l[N];
int r[N];
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(l, 0);
	MEM(r, 0);
	MEM(cnt, 0);
	int n;
	cin >> n;
	int maxv = 0;
	int key = -1;
	int len = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (!l[x]) l[x] = i;
		r[x] = i;
		cnt[x]++;
		if (maxv < cnt[x])
		{
			maxv = cnt[x];
			key = x;
			len = r[x] - l[x];
		}
		else if (maxv == cnt[x])
		{
			if (len > r[x] - l[x])
			{
				len = r[x] - l[x];
				key = x;
			}
		}
	}
	cout << l[key] << ' ' << r[key] << endl;
	return 0;
}