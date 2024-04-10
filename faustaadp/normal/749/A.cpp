#include<bits/stdc++.h>
using namespace std;
int n,nn,i;
int main()
{
	cin>>n;
	if(n%2==0)		
	{
		nn=n/2;
		cout<<nn<<endl;
		for(i=1;i<=nn;i++)
		{
			if(i==nn)
				cout<<"2\n";
			else
				cout<<"2 ";
		}
	}	
	else
	{
		nn=(n/2);
		cout<<nn<<endl;
		for(i=1;i<=nn;i++)
		{
			if(i==nn)
				cout<<"3\n";
			else
				cout<<"2 ";
		}
	}
	return 0;
}