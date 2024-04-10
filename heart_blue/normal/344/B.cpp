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
int a[3][3];
int b[3];
int main()
{
	//freopen("input.txt","r",stdin);
	int x,y,z;
	int maxv = -1;
	for(int i = 0; i < 3; i++)
	{
		cin >> b[i];
		if(b[i] > maxv)
		{
			maxv = b[i];
			x = i;
		}
	}
	y = (x+1)%3;
	z = (y+1)%3;
	if(b[y] < b[z]) swap(y,z);
	MEM(a,0);
	a[x][y] = a[y][x] = b[y] - b[z];
	b[x] -= b[y] - b[z];
	if(b[x] & 1)
	{
		cout << "Impossible" << endl;
		return  0;
	}
	if(b[z] * 2 < b[x])
	{
		cout << "Impossible" << endl;
		return 0;
	}
	a[x][y] += b[x]/2;
	a[y][x] = a[x][y];
	a[x][z] += b[x]/2;
	a[z][x] = a[x][z];
	a[y][z] = a[z][y] = b[z] - b[x]/2;
	cout << a[0][1] << ' ' << a[1][2] << ' '<< a[0][2]<< endl;
	
	
	
	return 0;
}