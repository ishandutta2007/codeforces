#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,m,x[2],y[2],i,j,k,z[2];
string s1,s2,s3;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>s1>>s2;
	n=s1.length();
	m=s2.length();
	for(i=0;i<n;i++)x[s1[i]-'0']++;
	for(i=0;i<m;i++)y[s2[i]-'0']++;
	j=0;
	for(i=1;i<m;i++)
	{
		if(s2[i]==s2[j])
			j++;
		else
		{
			j=0;
			if(s2[i]==s2[j])
				j++;
		}
	}
	//cout<<j<<"\n";
	s3=s2.substr(j,m-j);
	k=s3.length();
	for(i=0;i<k;i++)z[s3[i]-'0']++;
	//cout<<s3<<"\n";
	if(y[0]<=x[0]&&y[1]<=x[1])
	{
		cout<<s2;
		x[0]-=y[0];
		x[1]-=y[1];
	}
	while(z[0]<=x[0]&&z[1]<=x[1])
	{
		cout<<s3;
		x[0]-=z[0];
		x[1]-=z[1];
	}
	for(i=0;i<m;i++)
	{
		if(s2[i]=='0'&&x[0]>=1)
		{
			cout<<'0';
			x[0]--;
		}
		else
		if(s2[i]=='1'&&x[1]>=1)
		{
			cout<<'1';
			x[1]--;
		}
		else
		if(x[0]>=1)
		{
			cout<<'0';
			x[0]--;
		}
		else
		if(x[1]>=1)
		{
			cout<<'1';	
			x[1]--;
		}
	}
	//cout<<"_"<<x[0]<<" "<<x[1]<<"_\n";
	for(i=0;i<x[0];i++)cout<<'0';
	for(i=0;i<x[1];i++)cout<<'1';
	cout<<"\n";
}