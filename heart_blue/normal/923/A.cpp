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
const int N = 1e6 + 10;
int a[N];
vector<int> v[N];
void init()
{
	MEM(a, 0);
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		v[i].push_back(i);
		for (int j = i + i; j < N; j += i)
		{
			v[j].push_back(i);
			a[j] = 1;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	cin >> n;
	int ans = n - 1;
	for (int i = n - 1; i > n - v[n].back(); i--)
	{
		if (a[i] == 0) continue;
		ans = min(ans, i - v[i].back() + 1);
	}
	cout << ans << endl;
	return 0;
}