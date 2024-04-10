#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s,z;
ll i,k,nm,n,mm;
bool bb,b[1010];
int main()
{
	cin>>s;
	for(i=0;i<s.length();i++)
		b[s[i]]=1;
	cin>>s;
	if(0<=s.find("*")&&s.find("*")<s.length())
	{
		k=s.find("*");
	}
	else
		k=-1;
	nm=s.length();
	cin>>n;	
	while(n--)
	{
		cin>>z;
		bb=1;
		mm=z.length();
		if(k!=-1)
		{
			if(mm+1<nm)
				bb=0;
			else
			{
				for(i=0;i<k;i++)
				{
		//			cout<<i;
					if(s[i]=='?')
					{
						if(b[z[i]]==0)
						{
							bb=0;
							break;
						}
					}
					else
					{
						if(s[i]!=z[i])
						{
							bb=0;
							break;
						}
					}
				}
		//		cout<<'\n';
				for(i=k;i<=k+(mm-nm);i++)
				{
		//			cout<<i;
					if(b[z[i]]==1)
					{
						bb=0;
						break;
					}
				}
		//		cout<<'\n';
				for(i=k+1+(mm-nm);i<mm;i++)
				{
		//			cout<<i;
					if(s[i-(mm-nm)]=='?')
					{
						if(b[z[i]]==0)
						{
							bb=0;
							break;
						}
					}
					else
					{
						if(s[i-(mm-nm)]!=z[i])
						{
							bb=0;
							break;
						}
					}
				}
		//		cout<<'\n';
			}
		}
		else
		if(k==-1)
		{
			if(mm<nm)
				bb=0;
			else
			{
				for(i=0;i<mm;i++)
				{
					if(s[i]=='?')
					{
						if(b[z[i]]==0)
						{
							bb=0;
							break;
						}
					}
					else
					{
						if(s[i]!=z[i])
						{
							bb=0;
							break;
						}
					}
				}
			}
		}
		if(bb)	cout<<"YES\n";
		else	cout<<"NO\n";
	}
}