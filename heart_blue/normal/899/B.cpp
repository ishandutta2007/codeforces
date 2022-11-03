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
const int N = 1e5 + 10;
int a[2][13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31,
				0,31,29,31,30,31,30,31,31,30,31,30,31 };
int b[N];
int k = 0;
bool isLeap(int y)
{
	if (y % 100 == 0) return y % 400 == 0;
	else return y % 4 == 0;
}
void init()
{
	for (int i = 2090; i <= 2200; i++)
	{
		for (int m = 1; m <= 12; m++)
		{
			b[k++] = a[isLeap(i)][m];
		}
	}
}
bool check(vector<int> &v, int x)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != b[x + i]) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	for (int i = 0; i < 300; i++)
	{
		if (check(v, i))
		{
			cout << "yes" << endl;
			return 0;
		}
	}
	cout << "no" << endl;
	return 0;
}