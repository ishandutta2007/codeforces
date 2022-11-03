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
const int N = 30;

int main()
{
	//freopen("input.txt", "r", stdin);
	int a, b, v, k;
	cin >> k >> a >> b >> v;
	int cnt = 0;
	k--;
	while (a > 0)
	{
		int t;
		cnt++;
		if (b >= k)
		{
			t = k + 1;
			b -= k;
		}
		else
		{
			t = b + 1;
			b = 0;
		}
		a -= v*t;
	}
	cout << cnt << endl;
	return 0;
}