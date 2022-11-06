#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
string s;
ll n,i,j;
ll opt1[101010];
ll opt2[101010];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.length();
	for(i=0;i<=0;i++)
	{
		ll tem=0,tem2=0,tem3=0,tem4=0;
		for(j=i;j<n;j++)
		{
			if(s[j]=='0')
				tem++;
			else
				tem2++;
			opt1[j]=max(tem2,tem);
			if(s[j]=='1')
				tem4=max(tem4+1,tem+1);
			opt1[j]=max(opt1[j],tem4);
		}
	}
	for(i=n-1;i<=n-1;i++)
	{
		ll tem=0,tem2=0,tem3=0,tem4=0;
		for(j=i;j>=0;j--)
		{
			if(s[j]=='1')
				tem++;
			else
				tem2++;
			opt2[j]=max(tem2,tem);
			if(s[j]=='0')
				tem4=max(tem4+1,tem+1);
			opt2[j]=max(opt2[j],tem4);
			//cout<<j<<" "<<i<<" "<<opt[j][i]<<"\n";
		}
	}
	for(i=0;i<n;i++)
	{
		ll gagal=0;
		for(j=n-1;j<n;j++)
		{
			if(opt2[i]!=(opt2[i+1]+1))
				gagal=1;
		}
		for(j=0;j<=0;j++)
		{
			if(opt1[i]!=(opt1[i-1]+1))
				gagal=1;
		}
		//cout<<i<<" "<<gagal<<"\n";
		if((gagal==0)&&(s[i]=='1'))
			s[i]='0';
	}
	cout<<s<<"\n";
}