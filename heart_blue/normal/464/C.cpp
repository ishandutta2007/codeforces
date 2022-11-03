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
const int N = 1e4 + 10;
string str;
vector<string> vs;
pair<LL, LL> p[300];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> str;
	int n;
	cin >> n;
	vs.resize(n);
	for (auto &s : vs) cin >> s;
	reverse(vs.begin(), vs.end());
	vs.push_back("0->" + str);
	for (int i = '0'; i <= '9'; i++) p[i] = { 10LL,(i - '0') * 1LL };
	for (auto &s : vs)
	{
		LL pro = 1;
		LL sum = 0;
		for (int i = 3; i < s.length(); i++)
		{
			pro = pro * p[s[i]].first % INF;
			sum = (sum * p[s[i]].first + p[s[i]].second)%INF;
		}
		p[s[0]] = { pro,sum };
	}
	printf("%lld\n", p['0'].second);
	return 0;
}