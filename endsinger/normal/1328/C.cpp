#include<bits/stdc++.h>
using namespace std;
const int N=50005;
string s,s1,s2;
int n,t;
int main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		s1=s2="1";
		int fl=0;
		for(int i=1;i<n;i++)
		{
			if(s[i]=='0')
			{
				s1+='0';
				s2+='0';
			}
			if(s[i]=='1')
			{
				if(!fl)
				{
					s1+='0';
					s2+='1';
					fl=1;
				}
				else
				{
					s1+='1';
					s2+='0';
				}
			}
			if(s[i]=='2')
			{
				if(!fl)
				{
					s1+='1';
					s2+='1';
				}
				else
				{
					s1+='2';
					s2+='0';
				}
			}
		}
		cout<<s1<<endl<<s2<<endl;
	}
	return 0;
}