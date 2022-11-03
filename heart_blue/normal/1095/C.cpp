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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	priority_queue<int> pq;
	for (int i = 0; n >> i; i++)
	{
		if (n >> i & 1)
			pq.push(1 << i);
	}
	if (k > n || k < pq.size()) puts("NO"), exit(0);
	while (pq.size() < k)
	{
		int x = pq.top();
		pq.pop();
		pq.push(x / 2);
		pq.push(x / 2);
	}
	puts("YES");
	while (!pq.empty())
	{
		printf("%d ", pq.top());
		pq.pop();
	}
	return 0;
}