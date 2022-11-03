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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
int a[N];
int b[N];
int c[N];
int flag[N];
bool check(int n)
{
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != c[i]) cnt1++;
		if (b[i] != c[i]) cnt2++;
	}
	return cnt1 == 1 && cnt2 == 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	vector<int> v1, v2;
	MEM(flag, 0);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == b[i]) flag[a[i]] = 1, c[i] = a[i];
		else v1.push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!flag[i]) v2.push_back(i);
	}
	c[v1.front()] = v2.front();
	c[v1.back()] = v2.back();
	if (!check(n))
	{
		c[v1.front()] = v2.back();
		c[v1.back()] = v2.front();
		check(n);
	}
	for (int i = 1; i <= n; i++) cout << c[i] << ' ';



	return 0;
}