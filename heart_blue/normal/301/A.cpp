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
	int a[400];
	int n;
	cin >> n;
	int sum = 0;
	int t = 0;
	int mm = 10000000;
	for(int i = 0; i < n+n-1; i++)
	{
		cin >> a[i];
		if(a[i] < 0)
		{
			a[i] = -a[i];
			t ++;
			
		}
		mm = MIN(mm,a[i]);
		sum += a[i];
	}
	if(!(n&1) && (t&1))
	{
		sum -= 2*mm;
	}
	cout << sum << endl;
	return 0;
}