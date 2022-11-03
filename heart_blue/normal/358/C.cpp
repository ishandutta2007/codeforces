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
int a[N];
int flag[N];
class Q
{
public:
	int sz;
	Q()
	{
		sz = 0;
	}
	virtual string push(int x) = 0;
	virtual string pop() = 0;
};
class Queue : public Q
{
private:
	string push(int x)
	{
		sz++;
		return "pushQueue";
	}
	string pop()
	{
		if (sz > 0)
		{
			sz--;
			return "popQueue";
		}
		return "";
	}
};
class Stack : public Q
{
	string push(int x)
	{
		sz++;
		return "pushStack";
	}
	string pop()
	{
		if (sz > 0)
		{
			sz--;
			return "popStack";
		}
		return "";
	}
};
class Deque : public Q
{
	string push(int x)
	{
		if (x != 0)
		{
			sz++;
			return "pushFront";
		}
		else
		{
			return "pushBack";
		}
	}
	string pop()
	{
		if (sz > 0)
		{
			sz--;
			return "popFront";
		}
		return "";
	}
};
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == 0)
		{
			int cnt = 3;
			while (!pq.empty() && cnt--)
			{
				int pos = pq.top().second;
				flag[pos] = 1;
				pq.pop();
			}
			while (!pq.empty()) pq.pop();
		}
		else
		{
			pq.push({ a[i],i });
		}
	}
	Q* q[3] = { new Stack(), new Queue(), new Deque() };
	int o = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			if (flag[i] == 0) cout << q[2]->push(0) << '\n';
			else cout << q[o++]->push(a[i]) << '\n';
			if (o == 3) o = 0;
		}
		else
		{
			vector<string> ans;
			for (int k = 0; k < 3; k++)
			{
				ans.push_back(q[k]->pop());
				if (ans.back().empty()) ans.pop_back();
			}
			cout << ans.size();
			for (auto &str : ans) cout << ' ' << str;
			cout << '\n';
		}
	}
	return 0;
}