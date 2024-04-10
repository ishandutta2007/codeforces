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

const long long N = 1e5+1;
long long TA[N];
int n;

int lowbit(int x) 
{ 
    return x & -x; 
} 
             


long long Sum(int x) 
{ 
    long long sum = 0; 
    while(x > 0) 
    { 
        sum = max(sum,TA[x]); 
        x -= lowbit(x); 
    } 
    return sum; 
} 


void add(int pos , int x) 
{ 
	LL sum = Sum(pos)+1;
    while(pos <= n) 
    { 
          TA[pos] = max(TA[pos],sum); 
          pos += lowbit(pos); 
    } 
} 
int main()
{
//	freopen("input.txt","r",stdin);

	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		add(x,1);
		ans = max(ans,(int)Sum(x));
	}
	cout << ans << endl;
	return 0;



}