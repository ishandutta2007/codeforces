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
	vector<string> vs(n);
	for (auto &str : vs)
	{
		cin >> str;
		str += str;
	}
	int m = vs[0].length() / 2;
	int ans = INF;
	for (int i = 0; i < m; i++)
	{
		string str = vs[0].substr(i, m);
		int tot = 0;
		for (auto &s : vs)
		{
			int o = s.find(str);
			if (o == -1)
			{
				cout << -1 << endl;
				return 0;
			}
			tot += o;
		}
		ans = min(ans, tot);
	}
	cout << ans << endl;
	return 0;
}