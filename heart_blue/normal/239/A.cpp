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
int a[100000];
int main()
{
	int y,n,k;
	cin >> y >> k >> n;
	int x = y+(k-y%k);
	int s = 0;
	if(x == 0) x+= k;
	for(; x <= n; x+=k)
	{
		a[s++] = x-y;
	}
	if(s == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << a[0];
		for(int i = 1; i < s; i++)
			cout << ' ' << a[i];
		cout << endl;
	}
	return 0;
}