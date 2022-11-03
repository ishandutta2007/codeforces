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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;

int a[N];
vector<int> v;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	MEM(a, 0xFF);
	int maxv = 0;
	int tot = 1;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') v.push_back(i);
		else
		{
			if (!v.empty())
			{
				int x = v.back();
				v.pop_back();
				a[i] = x;
				if (x != 0 && a[x - 1] != -1) a[i] = a[x - 1];
				if (i - a[i] + 1 > maxv) maxv = i - a[i] + 1, tot = 0;
				if (i - a[i] + 1 == maxv) tot++;
			}
		}
	}
	cout << maxv << ' ' << tot << endl;
	return 0;
}