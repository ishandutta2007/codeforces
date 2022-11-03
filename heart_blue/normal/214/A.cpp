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
//#include "BigNum.h"
using namespace std;
ifstream fin("aa.txt");
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MEM(x) (memset((x),0,sizeof((x))))

int main()
{
	int n,m;
	cin >> n >> m;
	int count = 0;
	for(int a = 0; a <= m; a++)
	{
		for(int b = 0; b <= n; b++)
		{
			if(a*a+b == n && a + b*b == m)
			{
				count ++;
			}
		}
	}
	cout << count  << endl;
	return 0;
}