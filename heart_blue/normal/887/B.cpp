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
int a[N];
void check(vector<int> &v1, vector<int> &v2, vector<int> &v3)
{
	for (auto &x : v1)
	{
		if (x == 0) continue;
		a[x] = 1;
		for (auto &y : v2)
		{
			a[x * 10 + y] = 1;
			for (auto &z : v3)
			{
				a[x * 100 + y * 10 + z] = 1;
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v[3];
	for (int i = 0; i < n; i++)
	{
		v[i].resize(6);
		for (auto &x : v[i]) cin >> x;
	}
	int b[3] = { 0,1,2 };
	do
	{
		check(v[b[0]], v[b[1]], v[b[2]]);
	} while (next_permutation(b, b + 3));
	for (int i = 1; i < N; i++)
	{
		if (a[i] == 0)
		{
			cout << i - 1 << endl;
			break;
		}
	}
	return 0;
}