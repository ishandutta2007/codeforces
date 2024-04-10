#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,s,i,ta,tb,a[1010],has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>s;
	for(i=1;i<=n;i++)
	{
		cin>>ta>>tb;
		a[i]=ta*60+tb;
	}
	if(s+1<=a[1])
	{
		cout<<"0 0\n";
		return 0;
	}
	for(i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]>=(s+1)*2)
		{
			has=a[i-1]+s+1;
			//cout<<has<<"\n";
			cout<<has/60<<" "<<has%60<<"\n";
			return 0;
		}
	}
	has=a[n]+s+1;
	cout<<has/60<<" "<<has%60<<"\n";
}