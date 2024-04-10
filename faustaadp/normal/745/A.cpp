#include<bits/stdc++.h>
using namespace std;
string s,z[100];
int n,i,has;
int main()
{
	cin>>s;
	has=1;
	n=s.length();
	for(i=0;i<n;i++)
	{
		z[i]=s;
		s=s[n-1]+s.substr(0,n-1);
	//	cout<<z[i]<<endl;
	}
	sort(z,z+n);
	for(i=0;i<n-1;i++)
	{
		if(z[i]!=z[i+1])
			has++;
	}
	cout<<has<<endl;
}