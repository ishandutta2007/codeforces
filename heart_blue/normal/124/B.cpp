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
const int N = 5e4 + 10;
int getnum(string &str, vector<int> &v)
{
	int ret = 0;
	for (auto &x : v)
	{
		ret *= 10;
		ret += str[x] - '0';
	}
	return ret;
}
vector<string> vs;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vs.resize(n);
	for (auto &str : vs) cin >> str;
	vector<int> v;
	for (int i = 0; i < k; i++) v.push_back(i);
	int ans = INF;
	do
	{
		int minv = INF;
		int maxv = 0;
		for (auto &str : vs)
		{
			int x = getnum(str, v);
			minv = min(x, minv);
			maxv = max(x, maxv);
		}
		ans = min(ans, maxv - minv);
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
	return 0;
}