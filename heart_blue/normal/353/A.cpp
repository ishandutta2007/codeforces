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
	int a[4] = {0};
	int n;
	int x,y;
	cin >> n;
	int s1,s2;
	s1 = s2 = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		s1 += x;
		s2 += y;
		x &= 1;
		y &= 1;
		x <<= 1;
		a[x+y]++;
	}
	s1 &= 1;
	s2 &= 1;
	if(s1 == s2 && s1 == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	if(s1 + s2 == 1)
	{
		cout << -1 << endl; 
		return 0;
	}
	if(s1 == 1 && s2 == 1)
	{
		
		if((a[1] >= 1 || a[2] >= 1) && n > 1)
		{
			cout << 1 << endl;
			return 0;
		}
		cout << -1 << endl;
		return 0;
	}
	return 0;
}