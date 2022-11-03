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
const int N = 1e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int a = 0;
	int b = 0;
	while (n--)
	{
		string str;
		cin >> str >> str;
		if (str == "soft") a++;
		else b++;
	}
	if (a > b) swap(a, b);
	for (int i = 1; i <= 100; i++)
	{
		int cnt1 = (i * i + 1) / 2;
		int cnt2 = i * i - cnt1;
		if (b <= cnt1 && a <= cnt2)
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}