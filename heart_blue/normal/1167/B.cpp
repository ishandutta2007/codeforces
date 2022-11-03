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
int a[10];
int b[10] = { 0,4,8,15,16,23,42 };
vector<int> v[N * N];
vector<int> vp[10];
int ans[10];
int check(vector<int>& v1, vector<int>& v2)
{
	for (auto& x : v1)
	{
		for (auto& y : v2)
		{
			if (x == y) return x;
		}
	}
	return 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i <= 4; i++)
	{
		cout << "? " << i << ' ' << i + 1 << endl;
		cin >> a[i];
	}
	for (int i = 1; i <= 6; i++)
	{
		ans[6] ^= b[i];
		for (int j = i + 1; j <= 6; j++)
		{
			v[b[i] * b[j]].push_back(b[i]);
			v[b[i] * b[j]].push_back(b[j]);
		}
	}
	for (int i = 1; i <= 4; i++)
	{
		vp[i] = v[a[i]];
	}
	for (int i = 2; i <= 4; i++)
	{
		ans[i] = check(vp[i], vp[i - 1]);
	}
	ans[1] = a[1] / ans[2];
	ans[5] = a[4] / ans[4];
	for (int i = 1; i < 6; i++)
	{
		ans[6] ^= ans[i];
	}
	cout << "!";
	for (int i = 1; i <= 6; i++) cout << " " << ans[i];
	cout << endl;
	return 0;
}