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
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))
#define ABS(x) ((x) > 0 ? (x):(-x))

int main()
{
	//freopen("input.txt", "r", stdin);
	int n, p;
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		cin >> n >> p;
		int cnt = 2*n + p;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				cout << i << ' ' << j << endl;
				cnt--;
				if (cnt == 0) break;
			}
			if (cnt == 0) break;
		}
	}
	return 0;
}