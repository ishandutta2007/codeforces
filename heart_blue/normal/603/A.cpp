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
const int N = 3e5 + 10;

vector<int> v;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	int n;
	cin >> n >> str;
	str.push_back('*');
	int cnt = 0;
	char pre = str[0];
	int o = 0;
	for (auto &c : str)
	{
		if (c != pre)
		{
			v.push_back(cnt);
			cnt = 1;
		}
		else
		{
			cnt++;
		}
		pre = c;
		o = max(cnt, o);
	}
	int ans = v.size();
	if (o > 2) ans += 2;
	else
	{
		int y = 0;
		for (auto &x : v) if (x == 2) y++;
		if (y >= 2) ans += 2;
		else if(y == 1) ans++;
	}
	cout << ans << endl;
	return 0;
}