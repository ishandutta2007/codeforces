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
ifstream fin("aa.txt");
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))


int main()
{
	int n;
	cin >> n;
	int m = 2*3*5*7;
	if(n < 3)
	{
		cout << -1 << endl;
	}
	else if(n == 3)
	{
		cout << 210 << endl;
	}
	else
	{
		int r = 10;
		for(int i = 3; i <= n; i++)
		{
			r = (r*10)%m;
		}
		r = (m-r);
		cout << 1;
		for(int i = 4; i < n; i++)
		{
			cout << 0;
		}
		printf("%03d\n",r);
	}


	return 0;
}