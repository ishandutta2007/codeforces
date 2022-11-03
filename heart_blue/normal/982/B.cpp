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
pair<int, int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v + 1, v + n + 1);
	vector<int> ans;
	string str;
	cin >> str;
	int cur = 1;
	for (auto &c : str)
	{
		if (c == '0')
		{
			cout << v[cur].second << ' ';
			ans.push_back(v[cur++].second);
		}
		else
		{
			cout << ans.back() << ' ';
			ans.pop_back();
		}
	}
	return 0;
}