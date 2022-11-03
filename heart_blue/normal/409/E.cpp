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
int a[128][128];
int main()
{
	//freopen("input.txt", "r", stdin);
	string str1, str2;
	int a, b;
	double d;
	cin >> d;
	for (a = ceil(d * 2); a <= 10; a++)
	{
		for (int b = 1; b <= 10; b++)
		{
			if ((fabs(d*sqrt(a*a + 4.0*b*b) - a*b) < 1e-4))
			{
				cout << a << ' ' << b << endl;
				goto out;
			}
		}
	}
	out:
	return 0;
}