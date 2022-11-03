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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int a[N];
void init()
{
	string str = "{}<>()[]";
	MEM(a, 0);
	for (int i = 1; i < str.length(); i+=2)
	{
		a[str[i]] = str[i - 1];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	string str;
	cin >> str;
	stack<char> s;
	int ans = 0;
	for (auto &c : str)
	{
		if (a[c])
		{
			if (s.size() == 0)
			{
				puts("Impossible");
				return 0;
			}
			if (s.top() != a[c]) ans++;
			s.pop();
		}
		else s.push(c);
	}
	if(s.empty()) cout << ans << endl;
	else puts("Impossible");
	return 0;
}