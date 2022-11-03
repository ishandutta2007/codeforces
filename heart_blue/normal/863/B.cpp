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
const int N = 1e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	n *= 2;
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = INF;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			vector<int> v;
			for (int k = 0; k < n; k++)
			{
				if (k == i || k == j) continue;
				v.push_back(a[k]);
			}
			sort(v.begin(), v.end());
			int tmp = 0;
			for (int k = 0; k < v.size(); k += 2)
			{
				tmp += v[k + 1] - v[k];
			}
			ans = min(ans, tmp);
		}
	}
	cout << ans << endl;
	return 0;
}