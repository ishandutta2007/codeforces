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
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MEM(x) (memset((x),0,sizeof((x))))
const int N = 1000001;
int a[N];
int main()
{
	MEM(a);
	a[0] = a[1] = 1;
	for(int i = 2; i < N; i++)
	{
		if(a[i] == 0)
		{
			for(int j = i+i; j < N; j+= i)
			{
				a[j] = 1;
			}
		}
	}
	int n;
	long long d;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> d;
		long long t = long long(sqrt(double(d)));
		if(t*t != d) cout << "NO" << endl;
		else 
		{
			if(a[t] == 0) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;

}