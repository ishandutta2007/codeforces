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
	vector<int> v;
	int cnt = 0;
	int pre = 0;
	while (n--)
	{
		int x;
		cin >> x;
		if (x == pre) cnt++;
		else
		{
			v.push_back(cnt);
			cnt = 1;
		}
		pre = x;
	}
	v.push_back(cnt);
	int ans = 0;
	for (int i = 0; i + 1 < v.size(); i++)
	{
		ans = max(ans, 2 * min(v[i], v[i + 1]));
	}
	cout << ans << endl;
	return 0;
}