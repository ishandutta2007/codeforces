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
const int N = 3e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	vector<int> ans;
	cin >> n;
	int cur = 1;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x == cur)
		{
			ans.push_back(2000 + i);
			cur++;
		}
	}
	cout << ans.size() << endl;
	for (auto &x : ans) cout << x << ' ';
	return 0;
}