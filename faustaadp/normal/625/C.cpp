#include<bits/stdc++.h>
using namespace std;
long long n,k,i,j,ti,tu,a[1000][1000];
int main()
{
	cin>>n>>k;
	cout<<((((1)+(n*(k-1)))+(n*n)-(n-k))*n/2)<<endl;
	tu=n*(k-1);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j<k)
			{
				ti++;
				a[i][j]=ti;
			}		
			else
			{
				tu++;
				a[i][j]=tu;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j==n)
				cout<<a[i][j]<<endl;
			else
				cout<<a[i][j]<<" ";
		}
	}
}