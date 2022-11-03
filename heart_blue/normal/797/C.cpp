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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	MEM(cnt, 0);
	for (auto &c : str) cnt[c]++;
	int ptr = 'a';
	stack<char> sc;
	sc.push('z' + 2);
	for (auto &c : str)
	{
		cnt[c]--;
		while (ptr <= 'z' && cnt[ptr] == 0) ptr++;
		while (!sc.empty())
		{
			if (min(sc.top(), c) <= ptr)
			{
				if (c <= sc.top()) putchar(c), c = 'z' + 2;
				else putchar(sc.top()), sc.pop();
			}
			else break;
		}
		if (isalpha(c)) sc.push(c);
	}
	while (sc.size() > 1)
	{
		putchar(sc.top());
		sc.pop();
	}
	return 0;
}