#include <iostream>
#include <cmath>
#include<stdio.h>
#include <string>
#include <algorithm>
using namespace std;
string s;
long long a[5], k, i, j, u[100], ans, maxi, sum, b[6][6];
int main()
{
	for(i=0; i<5; i++)
	{
		a[i]=i;
	}
	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
		{
			cin>>b[i][j];
		}
	}
	ans=0;
	for(i=1; i<=120; i++)
	{
		sum=b[a[0]][a[1]]+2*b[a[2]][a[3]]+2*b[a[3]][a[4]]+b[a[1]][a[2]]+b[a[1]][a[0]]+2*b[a[3]][a[2]]+2*b[a[4]][a[3]]+b[a[2]][a[1]];
		maxi=max(sum, maxi);
		next_permutation(a, a+5);
	}
	ans=maxi;
	cout<<ans;
		
}