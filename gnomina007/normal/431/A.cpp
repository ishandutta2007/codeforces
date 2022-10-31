#include <iostream>
#include <cmath>
#include<stdio.h>
#include <string>
using namespace std;
string s;
long long a[100], k, i, j, u[100], ans;
int main()
{
	cin>>u[1]>>u[2]>>u[3]>>u[4];
	cin>>s;
	k=s.length();
	for(i=1; i<=k; i++)
	{
		a[s[i-1]-'0']++;
	}
	for(i=1; i<=4; i++)
	{
		ans=ans+u[i]*a[i];
	}
	cout<<ans;
}