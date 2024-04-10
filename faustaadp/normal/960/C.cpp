#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll du[1010],i,x,d,te,j;
vector<ll> v,v2;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	du[0]=1;
	for(i=1;i<=40;i++)
		du[i]=du[i-1]*2;
	for(i=1;i<=40;i++)
		du[i]--;
	cin>>x>>d;
	while(x>0)
	{
		for(i=40;i>=1;i--)
		{
			if(x>=du[i])
			{
				v.pb(i);
				x-=du[i];
				break;
			}
		}
	}
	te=1;
	for(i=0;i<v.size();i++)
	{
		for(j=0;j<v[i];j++)
			v2.pb(te);
		te+=d;
		te++;
	}
	cout<<v2.size()<<"\n";
	for(i=0;i<v2.size();i++)
		if(i+1==v2.size())
			cout<<v2[i]<<"\n";
		else
			cout<<v2[i]<<" ";
}