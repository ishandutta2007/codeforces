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

int a[5001];
int b[5001];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n;
	int x;
	MEM(a,0);
	int m = 0;
	int s = 1<< 30;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		//s = MIN(s,x);
		m = MAX(x,m);
		a[x]++;
	}
	MEM(b,0);
	for(int i = 1; i <= m; i++)
	{
		b[i] = a[i] + b[i-1];
	}
	int ans;
	if(m & 1)
	{
		ans = b[m]-b[m/2];
	}
	else
	{
		ans = b[m]-b[m/2-1];
	}
	for(int i = 1; i <= m/2; i++)
	{
		if(b[i])
			ans = MAX(ans,b[i+i] - b[i-1]);
	}
	cout  << n - ans << endl;




	return 0;
}