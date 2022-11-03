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
const int N = 1e3 + 10;
int days[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
int sum[20];
int getseconds(int m1, int d1, int h2, int m2, int s2)
{
	int d = sum[m1 - 1] + d1;
	return d * 24 * 3600 + h2 * 3600 + m2 * 60 + s2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i <= 12; i++)
		sum[i] = days[i] + sum[i - 1];
	int n, m;
	cin >> n >> m;
	string str;
	getline(cin, str);
	queue<int> q;
	while (getline(cin, str))
	{
		for (auto& c : str)
		{
			if (!isdigit(c))
				c = ' ';
		}
		stringstream sin(str);
		int y1, m1, d1;
		int h2, m2, s2;
		sin >> y1 >> m1 >> d1 >> h2 >> m2 >> s2;
		int cur = getseconds(m1, d1, h2, m2, s2);
		q.push(cur);
		while (!q.empty() && cur - q.front() >= n)
			q.pop();
		if (q.size() >= m)
		{
			printf("2012-%02d-%02d %02d:%02d:%02d\n", m1, d1, h2, m2, s2);
			return 0;
		}

	}
	puts("-1");
	return 0;
}