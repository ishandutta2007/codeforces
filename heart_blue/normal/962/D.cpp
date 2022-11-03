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
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	priority_queue<pair<LL, int>,vector<pair<LL, int>>,greater<pair<LL, int>>> pq;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pq.push({ a[i],i });
	}
	int tot = n;
	while (pq.size() > 1)
	{
		auto p1 = pq.top(); pq.pop();
		auto p2 = pq.top(); pq.pop();
		if (p1.first == p2.first)
		{
			a[p2.second] = p1.first + p2.first;
			a[p1.second] = -1;
			p2.first <<= 1;
			pq.push(p2);
			tot--;
		}
		else
		{
			pq.push(p2);
		}
	}
	cout << tot << endl;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == -1) continue;
		cout << a[i] << ' ';
	}
	return 0;
}