#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
using namespace std;
#define MAX (a,b) ((a)>(b)?(a):(b))
#define MIN (a,b) ((a)<(b)?(a):(b))
#define MEM(a,b) memset((a),(b),sizeof(a))
typedef long long LL;
typedef unsigned long long ULL;
int a[10];

int main()
{
	MEM(a,0);
	int n;
	cin >> n;
	int x;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		a[x] ++;
	}
	if(a[5] || a[7])
	{
		cout << -1 << endl;
		return 0;
	}
	if(a[1] != a[4] + a[6])
	{
		cout << -1 << endl;
		return 0;
	}
	if(a[2] < a[4])
	{
		cout << -1 << endl;
		return 0;
	}
	if(a[6] < a[3])
	{
		cout << -1 << endl;
		return 0;
	}
	if(a[4] + a[6] != a[2] + a[3])
	{
		cout << -1 << endl;
		return 0;
	}
	if(a[1] != a[2] + a[3])
	{
		cout << -1 << endl;
		return 0;
	}
	
	for(int i = 0; i < a[4]; i++)
	{
		a[2] --;
		cout << "1 2 4" << endl;
	}
	for(int i = 0; i < a[2]; i++)
	{
		cout << "1 2 6" << endl;
	}
	for(int i = 0; i < a[3]; i++)
	{
		cout << "1 3 6" << endl;
	}
	return 0;
}