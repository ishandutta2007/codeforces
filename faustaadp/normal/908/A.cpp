#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
string s;
ll n,i,hs;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		if(s[i]=='a'||s[i]=='i'||s[i]=='u'||s[i]=='e'||s[i]=='o'||s[i]=='1'||s[i]=='3'||s[i]=='5'||s[i]=='7'||s[i]=='9')
		{
//			cout<<i<<"\n";
			hs++;
		}
	}	
	cout<<hs<<"\n";
}