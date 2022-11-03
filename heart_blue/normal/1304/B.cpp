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
const int N = 3e5 + 10;
int flag[N];
bool check(string& s1, string& s2)
{
	string s = s1;
	reverse(s.begin(), s.end());
	return s == s2;
}
vector<string> vs;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string lans, rans;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		vs.emplace_back(str);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			if (flag[i]) break;
			if (flag[j]) continue;
			if (check(vs[i], vs[j]))
			{
				lans += vs[i];
				rans = vs[j] + rans;
				flag[i] = flag[j] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (flag[i]) continue;
		if (check(vs[i], vs[i]))
		{
			lans += vs[i];
			break;
		}
	}
	cout << lans.length() + rans.length() << endl;
	cout << lans << rans << endl;
	return 0;
}