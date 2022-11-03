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
const int N = 2e5 + 10;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> ans;
	char c;
	stack<int> s;
	int i = 0;
	int cur = -1;
	while (cin >> c)
	{
		i++;
		if (c == '(') s.push(i);
		else if (c == ')')
		{
			if (s.size() == 0)
			{
				ans.clear();
				break;
			}
			s.pop();
		}
		else
		{
			cur = i;
			if (s.size() == 0)
			{
				ans.clear();
				break;
			}
			ans.push_back(1);
			s.pop();
		}
	}
	if (ans.empty() || (!s.empty() && s.top() > cur)) cout << -1 << endl;
	else
	{
		ans[ans.size() - 1] += s.size();
		for (auto &x : ans) cout << x << endl;
	}
	return 0;
}