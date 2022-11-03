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
int flag[N];
int key[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	set<int> pos, s;
	MEM(flag, -1);
	int o = 1;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		key[a[i]] = i;
		s.insert(a[i]);
		pos.insert(i);
	}
	while (!s.empty())
	{
		o ^= 1;
		int x = *s.rbegin();
		int p = key[x];
		auto iter = pos.find(p);
		int tot = k;
		while (tot-- && iter != pos.begin())
		{
			iter--;
			flag[*iter] = o;
			s.erase(a[*iter]);
			iter = pos.erase(iter);
		}
		tot = k + 1;
		while (tot-- && iter != pos.end())
		{
			flag[*iter] = o;
			s.erase(a[*iter]);
			iter = pos.erase(iter);
		}
	}
	for (int i = 1; i <= n; i++) putchar(flag[i] + '1');
	return 0;
}