#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
using namespace std;
ll n,x,i,ta,tb,a[101010],hs,c[101010],n1,n2,d[101010];
vector<ll> v[101010];
vector<ll> k[10];
bool b[101010];
void rmt(ll aa,ll bb)
{
	ll ii;
//	cout<<aa<<" "<<bb<<"\n";
	for(ii=0;ii<c[aa];ii++)
	{
	//	cout<<v[aa][ii]<<"\n";
		if(d[v[aa][ii]]==0)
		{
			d[v[aa][ii]]=(bb%2)+1;
			k[(bb%2)+1].push_back(v[aa][ii]);
			rmt(v[aa][ii],(bb%2)+1);
		}
	}
}
int main()
{
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>ta>>tb;
		c[ta]++;
		c[tb]++;
		v[ta].push_back(tb);
		v[tb].push_back(ta);
	}
	d[1]=1;
	k[1].push_back(1);
	rmt(1,1);
	n1=k[1].size();
	n2=k[2].size();
//	cout<<n2<<"\n";
	for(i=0;i<n1;i++)
	{
		hs=hs+(n2-c[k[1][i]]);
	}
	cout<<hs<<"\n";
}