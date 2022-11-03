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
const LL INF = 1e9 + 1;
const int N = 2e6;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	int a, b;
	cin >> a >> b;
	int d = a*a + b*b;
	if (a == 0 || b == 0)
	{
		cout << "black" << endl;
		return 0;
	}
	for (int i = 1;; i++)
	{
		if (i*i == d)
		{
			cout << "black" << endl;
			return 0;
		}
		if (i*i > d)
		{
			if (i & 1)
			{
				if (a*b > 0) cout << "black" << endl;
				else cout << "white" << endl;
			}
			else
			{
				if (a*b > 0) cout << "white" << endl;
				else cout << "black" << endl;
			}
			return 0;
		}
		
	}

	return 0;
}