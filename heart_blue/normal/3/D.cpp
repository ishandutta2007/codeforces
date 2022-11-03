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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int o = 0;
	LL ans = 0;
	typedef pair<int, int> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') o++;
		else if (str[i] == ')') o--;
		else
		{
			str[i] = ')';
			o--;
			int l, r;
			cin >> l >> r;
			ans += r;
			pq.push({ l - r,i });
		}
		if (o < 0)
		{
			if (pq.empty()) break;
			int x, pos;
			tie(x, pos) = pq.top();
			pq.pop();
			ans += x;
			str[pos] = '(';
			o += 2;
		}
	}
	if (o == 0) printf("%lld\n%s\n", ans, str.c_str());
	else puts("-1");
	return 0;
}