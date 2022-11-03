#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
#include<queue>
#include<cmath>
using namespace std;
int a[105];
int main()
{
	int n,check1=0,check2=0,n1=0,n2=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(check1==0)
		{
		check1=a[i];
		n1++;
		continue;
	}
		
		
		if(a[i]==check1)
		{
		n1++;
		continue;
	}
		if(a[i]==check2)
		{
		n2++;
		continue;
	}
		if(check2==0)
		{
		check2=a[i];
		n2++;
		continue;
	}
	if(a[i]!=check1 and a[i]!=check2)
		{
			cout<<"NO";
			return 0;
		}
	}
	if(n1==n2)
	{
		cout<<"YES"<<endl<<check1<<' '<<check2;
	}
	else
	cout<<"NO";
	return 0;
}