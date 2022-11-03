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
	priority_queue<LL, vector<LL>, greater<LL>> pq;
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) pq.push(0);
	while (n--)
	{
		int s, m;
		scanf("%d%d", &s, &m);
		LL cur = max(s * 1LL, pq.top()) + m;
		pq.pop();
		printf("%lld\n", cur);
		pq.push(cur);
	}
	return 0;
}