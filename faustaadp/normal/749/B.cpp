#include<bits/stdc++.h>
using namespace std;
long long n,nn,i,x[5],y[5];
int main()
{
	for(i=1;i<=3;i++)
	{
		cin>>x[i]>>y[i];
	}
	if((x[1]==x[2]&&x[2]==x[3])||(y[1]==y[2]&&y[2]==y[3])||((x[3]-y[3])==(x[2]-y[2])&&(x[2]-y[2])==(x[1]-y[1])))
		cout<<0<<endl;
	else
	{
		cout<<3<<endl;
		cout<<x[3]+(x[2]-x[1])<<" "<<y[3]+(y[2]-y[1])<<endl;
		cout<<x[2]+(x[1]-x[3])<<" "<<y[2]+(y[1]-y[3])<<endl;
		cout<<x[1]+(x[3]-x[2])<<" "<<y[1]+(y[3]-y[2])<<endl;	
	}
	return 0;
}