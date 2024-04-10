#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,x,a[5050],d[5050][5050],i,j,has;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k>>x;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)d[1][i]=-1e18;
	for(i=n;i>(n-k);i--)d[1][i]=a[i];
	for(i=2;i<=x;i++)
	{
		deque<pair<ll,ll> > dq;
		for(j=n;j>=1;j--)
		{
			while(!dq.empty()&&(dq.front().se>(j+k)))dq.pop_front();
			if(dq.empty())d[i][j]=-1e18;
			else d[i][j]=dq.front().fi+a[j];
			while(!dq.empty()&&(dq.back().fi<=d[i-1][j]))dq.pop_back();
			dq.push_back(mp(d[i-1][j],j));
		//	cout<<i<<" "<<j<<" "<<d[i][j]<<"\n";
		}
	}
	has=-1;
	for(i=1;i<=k;i++)has=max(has,d[x][i]);
	cout<<has<<"\n";
}