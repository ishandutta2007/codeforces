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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	map<int, int> m1, m2;
	for (auto &x : v)
	{
		m1[x] = 1;
	}
	queue<int> q;
	for (auto &x : v)
	{
		if (m1[a - x] == 0)
		{
			m1[x] = 0;
			m2[x] = 1;
			q.push(x);
		}
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (m2[b - x] == 0)
		{
			if (m1[b - x] == 0 || m1[a - (b - x)] == 0)
			{
				cout << "NO" << endl;
				return 0;
			}
			else
			{
				q.push(b - x);
				q.push(a - (b - x));
				m1[b - x] = 0;
				m1[a - (b - x)] = 0;
				m2[b - x] = 1;
				m2[a - (b - x)] = 1;
			}
		}
	}
	cout << "YES" << endl;
	for (auto &x : v)
	{
		if (m1[x] == 1) printf("0 ");
		else printf("1 ");
	}

	return 0;
}