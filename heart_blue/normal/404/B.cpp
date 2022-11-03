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
const int N = 301;

int main()
{
	//freopen("input.txt", "r", stdin);
	double a, d;
	int n;
	cin >> a >> d >> n;
	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += d;
		sum -= int(sum / 4 / a) * 4 * a;
		if (sum < a)
		{
			printf("%f %f\n", sum, 0.0);
		}
		else if (sum < 2 * a)
		{
			printf("%f %f\n", a, sum - a);
		}
		else if (sum < 3 * a)
		{
			printf("%f %f\n", a - (sum - 2 * a), a);
		}
		else
		{
			printf("%f %f\n", 0.0, 4 * a - sum);
		}
	}
	return 0;
}