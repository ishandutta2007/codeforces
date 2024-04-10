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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
vector<string> vs;
void init()
{
	string s = "";
	for (char i = 'a'; i <= 'z'; i++)
	{
		vs.push_back(s + i);
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		for (char j = 'a'; j <= 'z'; j++)
		{
			vs.push_back(s + i + j);
		}
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		for (char j = 'a'; j <= 'z'; j++)
		{
			for (char k = 'a'; k <= 'z'; k++)
			{
				vs.push_back(s + i + j + k);
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		string str;
		cin >> str;
		for (auto& s : vs)
		{
			if (str.find(s) == str.npos)
			{
				puts(s.c_str());
				break;
			}
		}
	}
	return 0;
}