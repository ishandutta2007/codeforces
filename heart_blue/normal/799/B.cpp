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
#include <cassert>
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int p[N];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq[4];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		pq[x].push({ p[i],i });
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		pq[x].push({ p[i],i });
	}
	int m;
	cin >> m;
	MEM(flag, 0);
	while (m--)
	{
		int x;
		int ans = -1;
		cin >> x;
		while (1)
		{
			if (pq[x].empty()) break;
			int price, o;
			tie(price, o) = pq[x].top();
			pq[x].pop();
			if (flag[o]) continue;
			flag[o] = 1;
			ans = price;
			break;
		}
		cout << ans << ' ';
	}
	return 0;
}