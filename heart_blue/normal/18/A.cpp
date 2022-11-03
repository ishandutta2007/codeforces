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

const int INF = 1e6 + 3;
const int N = 1e3 + 1;
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, -1, 1, 0, 0 };
int dist(pair<int,int> p1, pair<int,int> p2)
{
	int dx = p1.first - p2.first;
	int dy = p1.second - p2.second;
	return dx*dx + dy*dy;
}

bool check(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
	
	int a = dist(p1, p2);
	int b = dist(p1, p3);
	int c = dist(p2, p3);
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);
	return a != 0 && a + b == c;
}
bool check(int a, int b, int c)
{
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);
	return b == 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	pair<int, int> p1 = { a, b }, p2 = { c, d }, p3 = { e, f };
	if (check(p1, p2, p3))
	{
		cout << "RIGHT" << endl;
		return 0;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (!check(i, j, k)) continue;
				if (check({ p1.first + dx[i], p1.second + dy[i] }, { p2.first + dx[j], p2.second + dy[j] }, { p3.first + dx[k], p3.second + dy[k] }))
				{
					cout << "ALMOST" << endl;
					return 0;
				}
			}
		}
	}
	cout << "NEITHER" << endl;
	return 0;
}