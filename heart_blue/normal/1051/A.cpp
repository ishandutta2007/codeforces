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
const int N = 2e2 + 10;
int pos[N];
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 'A'; i <= 'Z'; i++) pos[i] = 1;
	for (int i = '0'; i <= '9'; i++) pos[i] = 2;
	int a[3] = { 'a','A','0' };
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		string str;
		cin >> str;
		MEM(cnt, 0);
		for (auto &c : str) cnt[pos[c]]++;
		for (int i = 0; i < 3; i++)
		{
			if (cnt[i] <= 1) continue;
			for (int j = 0; j < 3; j++)
			{
				if (cnt[j] > 0) continue;
				for (auto &c : str)
				{
					if (pos[c] != i) continue;
					c = a[j];
					cnt[j]++;
					break;
				}
			}
		}
		cout << str << endl;
	}
	return 0;
}