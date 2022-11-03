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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	typedef pair<int, int> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		pq.push({ x + 1,(y-1)/4+1 });
	}
	while (!pq.empty())
	{
		Node p = pq.top();
		pq.pop();
		if (pq.empty())
		{
			int x, y;
			tie(x, y) = p;
			if (y <= 3)
			{
				cout << x + (y != 1) << endl;
				return 0;
			}
			pq.push({ x + 1, (y - 1) / 4 + 1 });
			continue;
		}
		if (p.second <= 3)
		{
			continue;
		}
		Node q = pq.top();
		if (p.first + 1 == q.second)
		{
			pq.pop();
			pq.push({ q.first,max((p.second - 1) / 4 + 1,q.second) });
		}
		else
		{
			pq.push({ p.first + 1,(p.second - 1) / 4 + 1 });
		}
	}
	return 0;
}