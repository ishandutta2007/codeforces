#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll h1,a1,c1,h2,a2,i;
string s,z[2];
int main()
{
	cin>>h1>>a1>>c1;
	cin>>h2>>a2;
	while(1)
	{
		if(h2<=a1)
		{
			s=s+"1";
			break;
		}
		else
		if(h1<=a2)
		{
			s=s+"0";
			h1+=c1;
		}
		else
		{
			s=s+"1";
			h2-=a1;
		}
		h1-=a2;
	}
	z[0]="HEAL";
	z[1]="STRIKE";
	cout<<s.length()<<"\n";
	for(i=0;i<s.length();i++)
		cout<<z[s[i]-'0']<<"\n";
}