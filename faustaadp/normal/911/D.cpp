#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,i,a[101010],j,hz,t,ta,tb;
bool rmt(ll aa)
{
	ll hh=aa*(aa+1)/2;
	if(hh%2==1)
		return 1;
	else
		return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(a[i]>a[j])
				hz++;
		}
	}
	//cout<<hz<<"\n";
	hz=hz%2;
	cin>>t;
	while(t--)
	{
		cin>>ta>>tb;
		if(rmt(tb-ta))
			hz=1-hz;
		if(hz==0)
			cout<<"even\n";
		else
			cout<<"odd\n";
		
	}
}