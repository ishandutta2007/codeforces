#include<bits/stdc++.h>
using namespace std;
int n,i,k,nn;
int main()
{
	cin>>n>>k;
	nn=n;
	n=240-k;
	n=n/5;
	//cout<<n;
	i=1;
	while(i<=nn)
	{
		if((i*(i+1)/2)>n)
			break;
		i++;
	}
	cout<<i-1<<endl;
}