#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
char v[500][500];
int n, i, j, sum;
int main()
{
	cin>>n;
	sum=0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			cin>>v[i][j];
		}
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if((i+j)==(n-1))
			{
				if(i!=j)
				{
					if(v[i][j]==v[0][0])
				
					{
					sum++;				
					}
				}
			}
			if((i==j))
			{
				if(v[i][j]==v[0][0])	
				{
					sum++;
				}
			}
			
			if((i+j)!=(n-1))
			{
				if((i!=j))
				{ 
					if(v[i][j]==v[1][0])
					{
						sum++;
					}
					
				}
			}
		}
	}
	if(v[0][0]!=v[1][0])
	{
		sum++;
	}
	if(sum==(n*n+1))
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
}