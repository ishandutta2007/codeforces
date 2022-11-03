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
const int N = 2e5 + 10;
int a[N];
int b[N];
int cnt1[N];
int cnt2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	MEM(cnt1, 0);
	MEM(cnt2, 0);
	vector<int> v;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		v.push_back(a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
		v.push_back(b[i]);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		cnt1[lower_bound(v.begin(), v.end(), a[i]) - v.begin()]++;
	}
	for (int i = 0; i < m; i++)
	{
		cnt2[lower_bound(v.begin(), v.end(), b[i]) - v.begin()]++;
	}
	int rest = 0;
	for (int i = v.size(); i >= 0; i--)
	{
		if (cnt1[i] > cnt2[i] + rest)
		{
			cout << "YES" << endl;
			return 0;
		}
		rest += cnt2[i] - cnt1[i];
	}
	cout << "NO" << endl;
	return 0;
}