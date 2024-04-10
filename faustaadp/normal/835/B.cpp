#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k,i,hz,hs;
string s;
int main()
{
	cin>>k>>s;
	for(i=0;i<s.length();i++)
	{
		hz=hz+s[i]-'0';
	}
	sort(s.begin(),s.end());
	for(i=0;i<s.length();i++)
	{
		if(hz>=k)
			break;
		hz=hz+9-(s[i]-'0');
//		cout<<hz<<"\n";
		hs++;
	}
	cout<<hs<<"\n";
}