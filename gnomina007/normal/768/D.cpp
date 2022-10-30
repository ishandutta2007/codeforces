#include <iostream>;
#include <cmath>;
#include <vector>;
#include <stdio.h>;
#include <algorithm>;
#include <string>;
#include <set>;
using namespace std;
int k, q, p[1005], i, j, t;
double pi, e=0.0000001, df, cur, dyn[10005][1005];
int main()
{
	cin>>k>>q;
	for(i=0; i<q; i++)
	{
		cin>>p[i];
	}
	df= double(k-1)/double(k); 
	dyn[0][0]= double(1);
	for(i=1; i<10000; i++)
	{
		for(j=1; j<=k; j++)
		{
			dyn[i][j]=dyn[i-1][j]*double(j)/ double(k)+dyn[i-1][j-1]* double(k-j+1)/ double(k);
		}
	}
	for(i=0; i<q; i++)
	{
		t=0;
		pi=( double(p[i])-e)/ double(2000);
		for(j=0; j<10000; j++)
		{
			if(t==0)
			{
				if(dyn[j][k]>pi)
				{
					t++;
					cout<<j<<endl;
				}
			}
		}
	}
}