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
const int N = 5e2 + 10;
int a[N];
void init()
{
	for (int i = 0; i < N; i++) a[i] = i;
	for (int i = 'A'; i <= 'Z'; i++) a[i] = tolower(a[i]);
	a['0'] = 'o';
	a['1'] = 'l';
	a['i'] = a['I'] = 'l';
}
void change(string &str)
{
	for (auto &c : str) c = a[c];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	string str;
	cin >> str;
	int flag = 0;
	int n;
	cin >> n;
	change(str);
	while (n--)
	{
		string s;
		cin >> s;
		change(s);
		if (s == str)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}