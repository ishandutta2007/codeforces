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
	int n;
	cin >> n;
	int ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	stack<int> s;
	n *= 2;
	int cur = 1;
	while (n--)
	{
		string op;
		cin >> op;
		if (op[0] == 'r')
		{
			if (!s.empty())
			{
				if (s.top() == cur)
				{
					s.pop();
					cur++;
					continue;
				}
				else
				{
					ans++;
					while (!s.empty())
					{
						pq.push(s.top());
						s.pop();
					}
				}
			}
			pq.pop();
			cur++;
		}
		else
		{
			int x;
			cin >> x;
			s.push(x);
		}
	}
	cout << ans << endl;
	return 0;
}