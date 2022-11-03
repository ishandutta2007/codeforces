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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int flag[N];
int key[N];
void refrain(string& str)
{
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (isupper(str[i])) flag[i] = 1;
		else flag[i] = 0;
		str[i] = tolower(str[i]);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<string> vs(n);
	for (auto& s : vs) refrain(s);
	string str;
	refrain(str);
	char c;
	cin >> c;
	for (auto& s : vs)
	{
		int len = s.length();
		int cur = 0;
		while (1)
		{
			cur = str.find(s, cur);
			if (cur == -1) break;
			for (int i = 0; i < len; i++) key[i + cur] = 1;
			cur++;
		}
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (key[i])
		{
			if (str[i] != c) str[i] = c;
			else if (str[i] == 'a') str[i] = 'b';
			else str[i] = 'a';
		}
		if (flag[i]) str[i] = toupper(str[i]);
	}
	cout << str << endl;
	return 0;
}