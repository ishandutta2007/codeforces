#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll i,F[1010101],G[1010101],j,q;
ll p[12][1010101],ta,tb,tc;
ll f(ll aa)
{
	if(F[aa]==-1)
	{
		ll h=1;
		while(aa>0)
		{
			if(aa%10!=0)
				h*=(aa%10);
			aa/=10;
		}
		F[aa]=h;
	}
	return F[aa];
}
ll g(ll aa)
{
	if(G[aa]==-1)
	{
		if(aa<10)
			G[aa]=aa;
		else
			G[aa]=g(f(aa));
	}
	return G[aa];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(F,-1,sizeof(F));
	memset(G,-1,sizeof(G));
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=1000000;j++)
		{
			p[i][j]=p[i][j-1];
			if(g(j)==i)
				p[i][j]++;
		}
	}
	cin>>q;
	while(q--)
	{
		cin>>ta>>tb>>tc;
		cout<<p[tc][tb]-p[tc][ta-1]<<"\n";
	}
}