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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 9;
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int cur = 1;
	stack<int> s;
	s.push(INF);
	set<int, greater<int>> st;
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) st.insert(i);
	vector<int> ans;
	for (int i = 1; i <= k; i++)
	{
		int x;
		scanf("%d", &x);
		ans.push_back(x);
		st.erase(x);
		while (x > s.top())
		{
			if (cur != s.top())
			{
				puts("-1");
				return 0;
			}
			s.pop();
			cur++;
		}
		s.push(x);
	}
	for (int i = k + 1; i <= n; i++)
	{
		while (1)
		{
			auto iter = st.lower_bound(s.top());
			if (iter == st.end())
			{
				if (cur != s.top())
				{
					puts("-1");
					return 0;
				}
				cur++;
				s.pop();
			}
			else break;
		}
		auto iter = st.lower_bound(s.top());
		ans.push_back(*iter);
		s.push(*iter);
		st.erase(*iter);
	}
	for (auto &x : ans) printf("%d ", x);
	return 0;
}