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
const int N = 1e5 + 10;
char a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string op;
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char o;
		int x;
		cin >> o >> x;
		op.push_back(o);
		v.push_back(x);
	}
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < 10; i++)
	{
		int o = 1 << i;
		int a = 0, b = 1;
		for (int j = 0; j < n; j++)
		{
			if (op[j] == '&')
			{
				a &= (o&v[j]) >> i;
				b &= (o&v[j]) >> i;
			}
			if (op[j] == '|')
			{
				a |= (o&v[j]) >> i;
				b |= (o&v[j]) >> i;
			}
			if (op[j] == '^')
			{
				a ^= (o&v[j]) >> i;
				b ^= (o&v[j]) >> i;
			}
		}
		if (a == b)
		{
			z |= a << i;
		}
		else if (a == 0)
		{
			y |= 1 << i;
		}
		else
		{
			y |= 1 << i;
			z |= 1 << i;
		}
	}
	cout << 2 << endl;
	cout << "& " << y << endl;
	cout << "^ " << z << endl;
	return 0;
}