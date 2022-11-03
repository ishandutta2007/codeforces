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
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))
long long n;
long long sum(long long x)
{
	long long ans = 0;
	while(x)
	{
		ans += x%10;
		x /= 10;
	}
	return ans;
}
int digit(long long x)
{
	int cnt = 0;
	while(x)
	{
		cnt++;
		x /=10;
	}
	return cnt;
}

int main()
{
	cin >> n;
	long long t = int(sqrt(double(n)))+1;
	int cnt = digit(n)*9;
	long long ans = -1;
	for(long long i = t; i > 0; i--)
	{
		if(i*i+i*sum(i) == n)
		{
			ans = i;
		}
		if(i*i+i*cnt < n) break;
	}
	cout << ans << endl;
	return 0;
}