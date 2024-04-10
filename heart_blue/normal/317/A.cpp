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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))

int main()
{
	//freopen("input.txt","r",stdin);
	long long x,y,m;
	cin >> x >> y >> m;
	if(x >= m || y >= m)
	{
		cout << 0 << endl;
		return 0;
	}
	if(x > y) swap(x,y);
	if(y <= 0 && m > y)
	{
		cout << -1 << endl;
		return 0;
	}
	long long cnt = 0;
	if(x < 0)
	{
		cnt = (-x)/y;
		x = x%y;
		if(x >= m)
		{
			cout << cnt << endl;
			return 0;
		}
	}
	if(x > y) swap(x,y);
	while(1)
	{
		if(y >= m) break;
		cnt++;
		x = x+y;
		if(x > y) swap(x,y);
	}
	cout << cnt << endl;
	return 0;
}