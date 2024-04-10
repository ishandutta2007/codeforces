#include<bits/stdc++.h>
using namespace std;
int n,k,i,j,a,b,tam;
string s;
bool bb;
int main()
{
	//bb=1;
	cin>>n>>k;
	cin>>s;
	for(i=0;i<n;i++)
	{
		if(s[i]=='G')
			a=i;
		if(s[i]=='T')
			b=i;
	}
	if(b<a)
	{
		tam=a;
		a=b;
		b=tam;
	}
	if((b-a)%k==0)
	{
		bb=1;
		for(j=a;j<b;j=j+k)
		{
			if(s[j]=='#')
			{
			//	cout<<j;
				bb=0;
				break;
			}
		}
		if(bb==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	else
		cout<<"NO\n";
	return 0;
	
}