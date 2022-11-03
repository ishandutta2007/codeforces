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
ifstream fin("ab.txt");
#define MEM(x) (memset((x),0,sizeof((x))))
#define MIN(x,y) ((x)<(y)?(x):(y))



int main()
{
	long long ans, p,d;
	ans = 0;
	cin >> p >> d;
	long long k = 1;
	while(d)
	{
		if(p%10 == 9)
		{
			ans += 9*k;
			k *=10;
			p/=10;
			d/=10;
		}
		else
		{
			int t = p%10+1;
			if(t <= d)
			{
				ans += 9*k;
				k *= 10;
				p -= t;
				p /= 10;
				d -= t;
				d /= 10;
			}
			else break;
		}
	}
	cout << p*k+ans << endl;
	return 0;
}