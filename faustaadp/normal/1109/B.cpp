#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
string s;
ll n,i;
ll pal(string aa)
{
	ll ii;
	for(ii=0;ii<n;ii++)
		if(aa[ii]!=aa[n-ii-1])
			return 0;
	return 1;
}
ll sama(ll aa,ll bb)
{
	ll ii;
	for(ii=aa;ii<=bb;ii++)
		if(s[ii]!=s[aa])return 0;
	return 1;
}	
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>s;
	n=s.length();
	for(i=1;i<n;i++)
	{
		string s1=s.substr(0,i);
		string s2=s.substr(i,n-i);
		string s3=s2+s1;
		if(pal(s3)&&s3!=s)
		{
			cout<<1<<"\n";
			return 0;
		}
	}
	ll tengah=n/2;
	if(sama(0,tengah-1))cout<<"Impossible\n";
	else cout<<2<<"\n";
}