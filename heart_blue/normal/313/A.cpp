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
	int n;
	long long a[11];
	a[0] = 1;
	for(int i = 1; i < 11; i++) a[i] = a[i-1] * 10;
	cin >> n;
	if(n >= 0) cout << n << endl;
	else 
	{
		n = -n;
		int t = n/10;
		int s = n/100*10+n%10;
		if(n > t) n = t;
		if(n > s) n = s;
		cout << -n << endl;
	}

    return 0;

}