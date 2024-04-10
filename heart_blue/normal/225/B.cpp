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
const int N = 1e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int s, k;
	cin >> s >> k;
	list<pair<int, LL>> lp;
	lp.push_back({ k - 1,0 });
	lp.push_back({ 1,1 });
	LL sum = 1;
	vector<LL> v;
	v.push_back(sum);
	while (1)
	{
		int c;
		LL x;
		tie(c, x) = lp.front();
		lp.pop_front();
		lp.push_back({ 1,sum });
		v.push_back(sum);
		sum += sum - x;
		if (c > 1)
		{
			lp.push_front({ c - 1,x });
		}
		if (sum > INF) break;
	}
	reverse(v.begin(), v.end());
	vector<LL> ans;
	for (int i = 0; i < v.size(); i++)
	{
		if (s >= v[i])
		{
			int t = s / v[i];
			s %= v[i];
			while (t--) ans.push_back(v[i]);
		}
	}
	while (ans.size() < 2) ans.push_back(0);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}