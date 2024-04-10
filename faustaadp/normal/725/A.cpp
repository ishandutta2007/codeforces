#include<bits/stdc++.h>
using namespace std;
int n,i,hs;
char c[2500000];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	i=1;
	while(i<=n)
	{
		if(c[i]=='<')
			hs++;
		else
			break;
		i++;
	}
	i=n;
	while(i>=1)
	{
		if(c[i]=='>')
			hs++;
		else
			break;
		i--;
	}
	cout<<hs<<endl;
}