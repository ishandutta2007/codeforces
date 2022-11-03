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
const int N = 1e4 + 10;

void refrain(string &str)
{
	string s;
	int flag = 0;
	for (auto &c : str)
	{
		if (isalpha(c)) s.push_back(c);
		if (c == '_') s.push_back(" _"[flag]);
		if (c == ')') s += ") ", flag = 0;
		if (c == '(') s += " (", flag = 1;
	}
	str = s;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string str;
	cin >> str;
	refrain(str);
	stringstream sin(str);
	int ans = 0;
	int cnt = 0;
	while (sin >> str)
	{
		if (str[0] != '(') ans = max(ans, int(str.length()));
		else 
		{
			for (auto &c : str) if (!isalpha(c)) c = ' ';
			stringstream sin2(str);
			while (sin2 >> str) cnt++;

		}
	}
	cout << ans << ' ' << cnt << endl;
	return 0;
}