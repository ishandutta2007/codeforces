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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e5 + 10;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	queue<int> q;
	priority_queue<pair<int, int>> pq;
	int id = 0;
	while (n--)
	{
		int op, x;
		scanf("%d", &op);
		if (op == 1)
		{
			id++;
			int x;
			scanf("%d", &x);
			q.push(id);
			pq.emplace(x, -id);
		}
		if (op == 2)
		{
			while (flag[q.front()])
				q.pop();
			flag[q.front()] = 1;
			printf("%d ", q.front());
			q.pop();
		}
		if (op == 3)
		{
			while (flag[-pq.top().second])
				pq.pop();
			flag[-pq.top().second] = 1;
			printf("%d ", -pq.top().second);
			pq.pop();
		}
	}
	return 0;
}