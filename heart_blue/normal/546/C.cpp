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
const int N = 1e4 + 10;
vector<pair<int, string>> vp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int k1, k2;
	list<int> q1, q2;
	map<LL, int> m;
	cin >> n;
	cin >> k1;
	while (k1--)
	{
		int x;
		cin >> x;
		q1.push_back(x);
	}
	cin >> k2;
	while (k2--)
	{
		int x;
		cin >> x;
		q2.push_back(x);
	}
	int cnt = 0;
	int tot = 1;
	while (n--) tot *= (n + 1);
	while (!q1.empty() && !q2.empty())
	{
		int sum = 0;
		cnt++;
		if (cnt > tot) break;
		int x = q1.front(); q1.pop_front();
		int y = q2.front(); q2.pop_front();
		list<int> *p = nullptr;
		if (x < y) p = &q2;
		else p = &q1;
		p->push_back(min(x, y));
		p->push_back(max(x, y));
	}
	if (!q1.empty() && !q2.empty()) puts("-1");
	else if (q1.empty()) cout <<cnt << ' ' << 2 << endl;
	else cout << cnt << ' ' << 1 << endl;
	return 0;
}