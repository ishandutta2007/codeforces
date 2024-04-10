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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int p;
	cin >> p;
	LL ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++)
	{
		int b;
		cin >> b;
		pq.push(b);
		while (k < a[i] && !pq.empty())
		{
			ans += pq.top(), k += p;
			pq.pop();
		}
		if (k < a[i]) puts("-1"), exit(0);
	}
	cout << ans << endl;
	return 0;
}