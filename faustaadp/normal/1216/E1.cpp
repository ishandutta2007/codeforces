#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll x[101010],i,y[101010],z,o[101010],t,n;
string s[101010];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	x[0]=0;
	for(i=1;i<=100000;i++)
	{
		s[i]=to_string(i);
		o[i]=s[i].length();
		x[i]=x[i-1]+o[i];
		y[i]=y[i-1]+x[i];
	}
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<=100000;i++)
			if(y[i]>=n)
			{
				z=i;
				n-=y[i-1];
				break;
			}
		//cout<<n<<"_\n";
		for(i=1;i<=100000;i++)
		{
			//cout<<i<<" "<<o[i]<<"_\n";
			if(n<=o[i])
			{
				cout<<s[i][n-1]<<"\n";
				break;
			}
			n-=o[i];
		}
	}
}