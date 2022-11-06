#include<bits/stdc++.h>
using namespace std;
long long n,i,hs,o,bu,k;
string s;
int main()
{
	cin>>s;
	cin>>k;
	n=s.length();
	for(i=n-1;i>=1;i--)
	{
		if(s[i]=='0')
			o++;
		else
			bu++;
		if(o==k)
			break;
	}
	if(o<k)
		cout<<n-1;
	else
		cout<<bu<<endl;
	
}