#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,n,i,a[202020],mi[202020],jaw[202020];
char ct;
ll cek(ll aa)
{
	ll ii,las=0;
	for(ii=1;ii<=n;ii++)
	{
		if((a[ii]<=aa)&&(las<=a[ii])&&(mi[ii]==a[ii]))
		{
			jaw[ii]=1;
			las=a[ii];
		}
		else
			jaw[ii]=2;
	}
	for(ii=1;ii<=n;ii++)
	{
		if(jaw[ii]==2)
		{
			if(las>a[ii])
			{
				//cout<<aa<<" "<<ii<<"_\n";
				return 0;
			}
			las=a[ii];
		}
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>ct;
			a[i]=ct-'0';
		}
		mi[n+1]=1e18;
		ll ada=0;
		for(i=n;i>=1;i--)
			mi[i]=min(mi[i+1],a[i]);
		for(i=0;i<=9;i++)
			if(cek(i))
			{
				ada=1;
				break;
			}
		if(ada==0)cout<<"-\n";
		else
		{
			for(i=1;i<=n;i++)
				cout<<jaw[i];
			cout<<"\n";
		}
	}
}