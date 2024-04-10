#include<iostream>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	int k=2*n+1;
	int a[k][m];
	for(int i=0;i<m;i++)a[0][i]=1;
	for(int i=1;i<k;i++)
	{
		a[i][0]=1;
		for(int j=1;j<m;j++)
		a[i][j]=(a[i-1][j]+a[i][j-1])%1000000007;
	}
	cout<<a[k-1][m-1];
	return 0;
}