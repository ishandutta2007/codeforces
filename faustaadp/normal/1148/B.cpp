#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,k,ta,tb,a[202020],b[202020],i,has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>ta>>tb>>k;
	if(k>=n)
	{
		cout<<-1<<"\n";
		return 0;
	}
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=m;i++)
		cin>>b[i];
	for(i=1;i<=k+1;i++)
	{
		ll L=1,R=m,C,H=-1;
		while(L<=R)
		{
			C=(L+R)/2;
			if(a[i]+ta<=b[C])
			{
				H=C;
				R=C-1;
			}
			else
				L=C+1;
		}
		if(H==-1)
		{
			cout<<-1<<"\n";
			return 0;
		}
		H+=(k-i+1);
		if(H>m)
		{
			cout<<-1<<"\n";
			return 0;
		}
		has=max(has,b[H]+tb);
	}
	cout<<has<<"\n";

}