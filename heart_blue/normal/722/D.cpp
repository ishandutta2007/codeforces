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
int a[N];
priority_queue<pair<int, int>> pq;
map<int, int> mm;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		pq.push({ a[i],i });
		mm[a[i]] = 1;
	}
	while (!pq.empty())
	{
		int x, p;
		tie(x, p) = pq.top();
		int o = x;
		int k = x;
		while (o > 1)
		{
			o >>= 1;
			if (mm[o] == 0)
			{
				k = o;
				break;
			}
		}
		if (k == x) break;
		mm[x]--;
		mm[k]++;
		pq.pop();
		pq.push({ k,p });
	}
	while (!pq.empty())
	{
		int x, p;
		tie(x, p) = pq.top();
		pq.pop();
		a[p] = x;
	}
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
	return 0;
}