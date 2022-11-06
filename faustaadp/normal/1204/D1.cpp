#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
string s;
ll n,i,j,nol[2020][2020],opt[2020][2020];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		ll tem=0,tem2=0,tem3=0,tem4=0;
		for(j=i;j<n;j++)
		{
			if(s[j]=='0')
				tem++;
			else
				tem2++;
			nol[i][j]=tem;
			opt[i][j]=max(tem2,tem);
			if(s[j]=='1')
				tem4=max(tem4+1,tem+1);
			opt[i][j]=max(opt[i][j],tem4);
		}
	}
	for(i=0;i<n;i++)
	{
		ll gagal=0;
		for(j=i;j<n;j++)
		{
			if(opt[i][j]!=(opt[i+1][j]+1))
				gagal=1;
		}
		//cout<<i<<" "<<gagal<<"\n";
		for(j=0;j<=i;j++)
		{
//			if(i==4)
//				cout<<opt[j][i]<<" "<<opt[i+1][j]+1<<"_\n";
			if(opt[j][i]!=(opt[j][i-1]+1))
				gagal=1;
		}
		//cout<<i<<" "<<gagal<<"\n";
		if((gagal==0)&&(s[i]=='1'))
			s[i]='0';
	}
	cout<<s<<"\n";
}