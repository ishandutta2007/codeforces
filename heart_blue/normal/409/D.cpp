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

	int a[17];
	a[1] = 1;/**/
	a[2] = 0;/**/
	a[3] = 0;/**/
	a[4] = 1;/**/
	a[5] = 0;/**/
	a[6] = 1;
	a[7] = 0;/**/
	a[8] = 1;/**/
	a[9] = 1;/**/
	a[10] = 1;/**/
	a[11] = 0;/**/
	a[12] = 0;/**/
	a[13] = 1;/**/
	a[14] = 0;
	a[15] = 1;/**/
	a[16] = 0;/**/
	int n;
	cin >> n;
	cout << a[n];
	return 0;
}