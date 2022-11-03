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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int a[N][N];
int check(vector<int> &v)
{
	int n = 26;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i][j] && a[j][i])
			{
				v.push_back(a[i][j]);
				v.push_back(a[j][i]);
				return 2;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j])
			{
				for (int k = 0; k < n; k++)
				{
					if (a[j][k])
					{
						v.push_back(a[i][j]);
						v.push_back(a[j][k]);
						return 1;
					}
				}
			}
		}
	}
	v.push_back(-1);
	v.push_back(-1);
	return 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v;
	string s1, s2;
	int n;
	cin >> n >> s1 >> s2;
	int dis = 0;
	for (int i = 0; i < n; i++)
	{
		int x = s1[i] - 'a';
		int y = s2[i] - 'a';
		if (x == y) continue;
		a[x][y] = i + 1;
		dis++;
	}
	int d = check(v);
	cout << dis - d << endl;
	for (auto &x : v) cout << x << ' ';
	return 0;
}