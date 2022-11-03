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
const LL INF = 1e17;
const int N = 2e5 + 10;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a[256] = {};
	a['q'] = 9;
	a['r'] = 5;
	a['b'] = 3;
	a['n'] = 3;
	a['p'] = 1;
	char c;
	int w, b;
	w = b = 0;
	while (cin >> c)
	{
		if (islower(c))
		{
			w += a[c];
		}
		else
		{
			b += a[tolower(c)];
		}
	}
	if (w > b) cout << "Black";
	else if (w == b) cout << "Draw";
	else cout << "White";
	return 0;
}