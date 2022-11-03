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
	int n, k;
	cin >> n >> k;
	vector<int> v;
	v.push_back(-k - 1);
	for(int i = 0; i < n; i++)
	{
		int h, m;
		cin >> h >> m;
		v.push_back(h * 60 + m);
	}
	v.push_back(INF);
	for (int i = 0; i + 1 < v.size(); i++)
	{
		int ans = v[i] + k + 1;
		if (v[i + 1] > ans + k)
		{
			cout << ans / 60 << ' ' << ans % 60 << endl;
			return 0;
		}
	}

	return 0;
}