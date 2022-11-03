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
const int N = 1e2 + 10;
int flag[N];
int n;
int a[N];
int ask(int pos, int delta)
{
	cout << "?";
	for (int i = 1; i <= n; i++)
	{
		cout << ' ';
		if (i == pos) cout << 1 + delta;
		else cout << 1;
	}
	cout << endl;
	int id;
	cin >> id;
	return id;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	int last = n + 1;
	int cur = n;
	flag[0] = 1;
	while (cur > 0)
	{
		while (cur >= 0 && flag[cur]) cur--;
		if (cur <= 0) break;
		vector<int> v;
		v.push_back(cur);
		for (int i = 1; i <= n - 1; i++)
		{

			int id = ask(cur, i);
			if (flag[id] || id == cur) break;
			v.push_back(id);
		}
		while (!v.empty())
		{
			a[v.back()] = --last;
			flag[v.back()] = 1;
			v.pop_back();
		}
	}
	cout << "!";
	for (int i = 1; i <= n; i++)
		printf(" %d", a[i]);
	cout << endl;
	return 0;
}