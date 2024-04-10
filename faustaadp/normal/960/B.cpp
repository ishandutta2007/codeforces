#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k1,k2,i,a[101010],b[101010],u,has;
priority_queue<pair<ll,ll> > pq;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k1>>k2;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		cin>>b[i];
	for(i=1;i<=n;i++)
		pq.push(mp(abs(a[i]-b[i]),i));
	while(!pq.empty())
	{
		u=pq.top().se;
		if(k1>0)
		{
			k1--;
			if(a[u]>b[u])
				a[u]--;
			else
				a[u]++;
			pq.push(mp(abs(a[u]-b[u]),u));
		}
		else
		if(k2>0)
		{
			k2--;
			if(b[u]>a[u])
				b[u]--;
			else
				b[u]++;
			pq.push(mp(abs(a[u]-b[u]),u));
		}
		pq.pop();
	}
	for(i=1;i<=n;i++)
		has+=abs(a[i]-b[i])*abs(a[i]-b[i]);
	cout<<has<<"\n";
}