#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <cstdio>
#define N 21
using namespace std;

string a[N];
int m,n,grundy[2][N*2][N*2][N*2][N*2],delta;

int calc(int isOdd,int minSum,int maxSum,int minDif,int maxDif)
{
	if (minSum>maxSum || minDif>maxDif) return 0;
	if (grundy[isOdd][minSum][maxSum][minDif][maxDif]>=0) 
		return grundy[isOdd][minSum][maxSum][minDif][maxDif];
	set <int> s;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			if ((i+j)%2==isOdd && i+j>=minSum && i+j<=maxSum && i-j+delta>=minDif && i-j+delta<=maxDif)
			{
				if (a[i][j]=='L')
				{
					int x=calc(isOdd,minSum,i+j-1,minDif,maxDif);
					int y=calc(isOdd,i+j+1,maxSum,minDif,maxDif);
					s.insert(x^y);
				}
				if (a[i][j]=='R')
				{
					int x=calc(isOdd,minSum,maxSum,minDif,i-j+delta-1);
					int y=calc(isOdd,minSum,maxSum,i-j+delta+1,maxDif);
					s.insert(x^y);
				}
				if (a[i][j]=='X')
				{
					int x=calc(isOdd,minSum,i+j-1,minDif,i-j+delta-1);
					int y=calc(isOdd,minSum,i+j-1,i-j+delta+1,maxDif);
					int z=calc(isOdd,i+j+1,maxSum,minDif,i-j+delta-1);
					int t=calc(isOdd,i+j+1,maxSum,i-j+delta+1,maxDif);
					s.insert(x^y^z^t);
				}
			}
	int g=0;
	while (s.count(g)) g++;
	return grundy[isOdd][minSum][maxSum][minDif][maxDif]=g;
}

int main()
{
	cin >> m >> n;
	for (int i=0;i<m;i++) cin >> a[i];
	delta=n-1;
	memset(grundy,-1,sizeof(grundy));
	puts(calc(0,0,n+m-2,0,n+m-2)^calc(1,0,n+m-2,0,n+m-2)?"WIN":"LOSE");
}