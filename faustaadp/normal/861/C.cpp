#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll i,tt;
bool b[1010];
string s;
int main()
{
	cin>>s;
	b['a']=1;
	b['i']=1;
	b['u']=1;
	b['e']=1;
	b['o']=1;
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='a'||s[i]=='i'||s[i]=='u'||s[i]=='e'||s[i]=='o')
		{
			tt=0;
			cout<<s[i];
		}
		else
		{
			tt++;
			if(tt>=3&&(s[i-1]!=s[i]||s[i-2]!=s[i]))
			{
				tt=1;
				cout<<" ";
			}
			cout<<s[i];
		}
	}
	cout<<"\n";
}