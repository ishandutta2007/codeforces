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
vector<string> vs;
void init1(int n)
{
	string str = "abc";
	do
	{
		string key;
		for (auto& c : str)
		{
			for (int i = 0; i < n; i++) key += c;
		}
		vs.push_back(key);
	} while (next_permutation(str.begin(), str.end()));
}
void init2(int n)
{
	string str = "abc";
	do
	{
		string key;
		for (int i = 0; i < n; i++) key += str[0];
		for (int i = 0; i < n; i++) key += str[1], key += str[2];
		vs.push_back(key);
	} while (next_permutation(str.begin(), str.end()));
}
void init3(int n)
{
	string str = "abc";
	do
	{
		string key;
		for (int i = 0; i < n; i++) key += str[1], key += str[2];
		for (int i = 0; i < n; i++) key += str[0];
		vs.push_back(key);
	} while (next_permutation(str.begin(), str.end()));
}
void init(int n)
{
	init1(n);
	init2(n);
	init3(n);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	init(n);
	string s1, s2;
	cin >> s1 >> s2;
	for (auto& s : vs)
	{
		if (s.find(s1) != s.npos) continue;
		if (s.find(s2) != s.npos) continue;
		puts("YES");
		puts(s.c_str());
		return 0;
	}
	puts("NO");
	return 0;
}