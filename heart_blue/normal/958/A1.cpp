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
const int N = 1e6 + 10;
vector<string> vs;
void rot(vector<string>& vs)
{
	vector<string> vs2 = vs;
	int n = vs.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			vs[i][j] = vs2[n - j - 1][i];
		}
	}
}
void change1(vector<string>& vs)
{
	for (int i = 0; i < vs.size() - i - 1; i++)
	{
		swap(vs[i], vs[vs.size() - i - 1]);
	}
}
void change2(vector<string>& vs)
{
	int n = vs.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			swap(vs[i][j], vs[i][n - j - 1]);
		}
	}
}
vector<string> vs1, vs2;
void check()
{
	if (vs1 == vs2)
	{
		puts("Yes");
		exit(0);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vs1.resize(n);
	vs2.resize(n);
	for (auto& s : vs1) cin >> s;
	for (auto& s : vs2) cin >> s;
	for (int i = 0; i < 4; i++)
	{
		rot(vs1);
		check();
		change1(vs1);
		check();
		change1(vs1);
		change2(vs1);
		check();
		change2(vs1);
	}
	puts("No");
	return 0;
}