#include<bits/stdc++.h>
using namespace std;
long long i,hs,hh;
string s;
int main()
{
	cin>>s;
	for(i=0;i<s.length()-1;i++)
	{
		if(s[i]=='V'&&s[i+1]=='K')
		{
			hs++;
			s[i]='0';
			s[i+1]='0';
		}
	}
	//cout<<s<<hs<<endl;
	if(s.find("VV")<s.length())
	{
		hh=1;
	}
	else
	if(s.find("KK")<s.length())
	{
		hh=1;
	}
	cout<<hs+hh<<endl;
}