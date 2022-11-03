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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int a[] = { 2, 3 ,5 ,7 ,11, 13, 17, 19, 23, 29 ,31, 37, 41 ,43, 47, 53 ,59 ,61, 67 ,71, 73, 79 ,83, 89, 97 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int cur = 1;
	int n = 25;
	int p = -1;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (cur == 1)
		{
			if (a[i] * a[i] > 100) break;
		}
		else
		{
			if (a[i] * cur > 100) break;
		}
		cout << a[i] << endl;
		fflush(stdout);
		string str;
		cin >> str;
		if (str == "yes")
		{
			cnt++;
			if (cnt == 2) break;
			p = a[i];
			cur *= a[i];
		}
	}
	if (cnt == 2)
	{
		cout << "composite" << endl;
	}
	else if (cnt == 0)
	{
		cout << "prime" << endl;
	}
	else
	{
		cout << p * p << endl;
		fflush(stdout);
		string str;
		cin >> str;
		if (str == "yes") cout << "composite" << endl;
		else cout << "prime" << endl;
	}


	return 0;
}