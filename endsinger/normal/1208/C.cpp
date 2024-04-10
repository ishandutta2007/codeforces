#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,cnt,a[N][N];
void fill(int x,int y)
{
	for(int i=x;i<x+4;i++)
	{
		for(int j=y;j<y+4;j++)
		{
			a[i][j]=cnt;
			cnt++;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i+=4)
	{
		for(int j=1;j<=n;j+=4)
		{
			fill(i,j);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",a[i][j]);	
		} 
		puts("");
	}
	return 0;
}