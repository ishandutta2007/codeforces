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

int main()
{
	//freopen("input.txt", "r", stdin);
	int a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	int xa, ya, xb, yb;
	int flag = 0;
	for (xa = 1; xa < a; xa++)
	{
		ya = sqrt(a*a - xa*xa*1.0);
		if (ya*ya != a*a - xa*xa) continue;
		if (ya*b%a != 0) continue;
		xb = ya*b / a;
		if (xa*b%a != 0) continue; 
		yb = xa*b / a;
		flag = 1;
		cout << "YES" << endl;
		cout << "0 0" << endl;
		cout << xa << ' ' << ya << endl;
		cout << xb << ' ' << -yb << endl;
		break;
	}
	if (!flag) cout << "NO" << endl;
	return 0;
}