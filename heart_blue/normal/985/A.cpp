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
	vector<int> v(n / 2);
	for (auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	int ans = INF;
	for (int i = 0; i < 2; i++)
	{
		int sum = 0;
		for (int j = 0; j < v.size(); j++)
		{
			int x = (j + 1) * 2 - i;
			sum += abs(v[j] - x);
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}