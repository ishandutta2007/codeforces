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
	int n, m;
	cin >> n >> m;
	string s1, s2;
	cin >> s1 >> s2;
	int ans = INF;
	vector<int> v;
	for (int i = 0; i + n <= m; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < n; j++)
		{
			if (s1[j] != s2[i + j]) tmp.push_back(j);
		}
		if (ans > tmp.size()) ans = tmp.size(), v = tmp;
	}
	cout << ans << endl;
	for (auto &x : v) cout << x + 1 << ' ';
	return 0;
}