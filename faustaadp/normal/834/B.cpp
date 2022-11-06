#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
ll n,k,i,b1[10101],b2[10101],ma[10101010],ke[10101010],tt;
string s;
char c1,c2;
int main()
{
	cin>>n>>k;
	cin>>s;
	for(i=0;i<s.length();i++)
	{
		if(b1[s[i]]==0)
		{
			ma[i]++;
			b1[s[i]]=1;
		}
	}
	for(i=s.length()-1;i>=0;i--)
	{
		if(b2[s[i]]==0)
		{
			ke[i]++;
			b2[s[i]]=1;
		}
	}
	for(i=0;i<s.length();i++)
	{
		tt=tt+ma[i];
		if(tt>k)
		{
			cout<<"YES\n";
			return 0;
		}
		tt=tt-ke[i];
	}
	cout<<"NO\n";
}