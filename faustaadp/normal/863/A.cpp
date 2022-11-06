#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll i;
int main()
{
	cin>>s;
	while(s[s.length()-1]=='0')
	{
		s.erase(s.length()-1,1);
	}
	for(i=0;i<s.length()-i-1;i++)
	{
	//	cout<<i<<" "<<s.length()-i-1;
		if(s[i]!=s[s.length()-i-1])
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
}