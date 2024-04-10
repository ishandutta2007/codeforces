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
const int N = 200000;

int main()
{
	//freopen("input.txt", "r", stdin);
	LL cnt = 0;
	int n;
	cin >> n;
	int x;
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x == 1) cnt++;
		if (x == 0)ans += cnt;
	}
	cout << ans << endl;
	return 0;
}