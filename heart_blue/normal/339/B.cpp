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
	//freopen("input.txt","r",stdin);
	int s = 1;
	LL ans = 0;
	int n,m;
	cin >> n >> m;
	int x;
	for(int i = 0; i < m; i++)
	{
		cin >> x;
		if(x >= s)
		{
			ans += x-s;
			s = x;
		}
		else
		{
			ans += n+x-s;
			s = x;
		}
	}
	cout << ans << endl;
	return 0;
}