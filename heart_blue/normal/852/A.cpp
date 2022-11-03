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
#define MEM(x, y) memset((x),(y),sizeof(x))
const int INF = 1e9 + 7;
const int N = 1e5 + 10;
int sum(int n)
{
	int ret = 0;
	while (n)
	{
		ret += n % 10;
		n /= 10;
	}
	return ret;
}
string num2str(int x)
{
	string str;
	while (x)
	{
		str.push_back(x % 10 + '0');
		x /= 10;
	}
	reverse(str.begin(), str.end());
	return str;
}
void solve(int x)
{
	string str = num2str(x);
	int n = str.length() - 1;
	int key = 0;
	int tot = 0;
	for (int o = 0; o < (1 << n); o++)
	{
		tot = 0;
		int c = str[0] - '0';
		for (int i = 1; i < str.length(); i++)
		{
			if (o >> (i - 1) & 1)
			{
				tot += c;
				c = 0;
			}
			c = c * 10 + str[i] - '0';
		}
		tot += c;
		if (sum(tot) < 10)
		{
			key = o;
			break;
		}
	}
	putchar(str[0]);
	for (int i = 1; i < str.length(); i++)
	{
		if (key >> (i - 1) & 1) putchar('+');
		putchar(str[i]);
	}
	puts("");
	str = num2str(tot);
	for (int i = 0; i < str.length(); i++)
	{
		if (i) putchar('+');
		putchar(str[i]);
	}
	puts("");
}
bool check(int x)
{
	string str = num2str(x);
	int n = str.length() - 1;
	int key = 0;
	int tot = 0;
	for (int o = 0; o < (1 << n); o++)
	{
		tot = 0;
		int c = str[0] - '0';
		for (int i = 1; i < str.length(); i++)
		{
			if (o >> (i - 1) & 1)
			{
				tot += c;
				c = 0;
			}
			c = c * 10 + str[i] - '0';
		}
		tot += c;
		if (sum(tot) < 10) return 1;
	}
	return 0;
}
set<int> si;
#define pb push_back
vector<int> pp[233];
bool dis[2333333];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string str;
	cin >> str;
	int cur = 0;
	for (int i = 0; i < n; i++)
		cur += str[i] - '0';
	for (int i = 0; i+1 < n; i+=2)
		if(str[i]!='0') pp[str[i]-'0'].pb(i);
	int mx=-1,rq=0; pp[0].clear();
	for(int i=1;i<=9;++i)
	{
		int ne=0;
		while(!check(cur+ne*i*9)) ++ne;
		if(ne<=pp[i].size()) {mx=i; rq=ne; break;}
	}
	if(mx!=-1)
	{
	dis[0]=1;
	for(int i=0;i<rq;++i) dis[pp[mx][i]+1]=1;
	for (int i = 0; i < n; i++)
	{
		if(!dis[i]) putchar('+');
		putchar(str[i]);
	}
	puts("");
	solve(cur+rq*mx*9);
	return 0;
	}
	for(int i=1;i<=9;++i) pp[i].clear();
	for (int i = 1; i+1 < n; i+=2)
		if(str[i]!='0') pp[str[i]-'0'].pb(i);
	mx=-1,rq=0; pp[0].clear();
	for(int i=1;i<=9;++i)
	{
		int ne=0;
		while(!check(cur+ne*i*9)) ++ne;
		if(ne<=pp[i].size()) {mx=i; rq=ne; break;}
	}
	dis[0]=1;
	for(int i=0;i<rq;++i) dis[pp[mx][i]+1]=1;
	for (int i = 0; i < n; i++)
	{
		if(!dis[i]) putchar('+');
		putchar(str[i]);
	}
	puts("");
	solve(cur+rq*mx*9);
}