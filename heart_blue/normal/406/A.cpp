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
const int N = 1001;
int main()
{
	//freopen("input.txt", "r", stdin);
	int n;
	int x;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &x);
			if (i == j)  sum ^= x;
		}
	}
	int m;
	scanf("%d", &m);
	string ans;
	while (m--)
	{
		scanf("%d", &x);
		if (x == 3) ans += char(sum + '0');
		else
		{
			scanf("%d", &x);
			sum ^= 1;
		}
	}
	puts(ans.c_str());

	return 0;
}