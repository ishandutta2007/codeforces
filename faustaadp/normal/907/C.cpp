#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,hs,c[256],i,b[256];
char tc;
string s;
bool unk()
{
	ll ii,hh=0;
	for(ii='a';ii<='z';ii++)
	{
		if(b[ii]==2)
			hh++;
	}
	if(hh==25)
		return 1;
	else
		return 0;
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>tc;
		cin>>s;
		if(unk()&&t!=0&&(tc=='!'||tc=='?'))
			hs++;
		if(tc=='!')
		{
			memset(c,0,sizeof(c));
			for(i=0;i<s.length();i++)
			{
				if(b[s[i]]==0)
					b[s[i]]=1;
				c[s[i]]=1;
			}
			for(i='a';i<='z';i++)
				if(c[i]==0)
					b[i]=2;
		}
		else
		if(tc=='?')
		{
			b[s[0]]=2;
		}
		else
		if(tc=='.')
		{
			for(i=0;i<s.length();i++)
				b[s[i]]=2;
		}
	}
	cout<<hs<<"\n";
}