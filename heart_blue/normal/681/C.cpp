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
int op[N];
int num[N];
vector<string> vs = {"removeMin", "insert", "getMin"};
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	int n;
	scanf("%d", &q);
	n = 0;
	char s[20];
	int x;
	while (q--)
	{
		scanf("%s", s);
		if (s[0] == 'r')
		{
			if (pq.empty())
			{
				op[n] = 1;
				num[n] = 1e9;
				pq.push(1e9);
				n++;
			}
			op[n++] = 0;
			pq.pop();
		}
		if (s[0] == 'i')
		{
			scanf("%d", &x);
			op[n] = 1;
			num[n] = x;
			n++;
			pq.push(x);
		}
		if (s[0] == 'g')
		{
			scanf("%d", &x);
			while (!pq.empty() && pq.top() < x)
			{
				op[n++] = 0;
				pq.pop();
			}
			if (pq.empty() || pq.top() > x)
			{
				op[n] = 1;
				num[n] = x;
				n++;
				pq.push(x);
			}
			op[n] = 2;
			num[n] = x;
			n++;
		}
	}
	printf("%d\n", n);
	for (int i = 0; i < n; i++)
	{
		if (op[i]) printf("%s %d\n", vs[op[i]].c_str(), num[i]);
		else puts(vs[op[i]].c_str());
	}
	return 0;
}