#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,m,i,a[202020],j,has;
vector<ll> isi[202020];	
queue<pair<ll,ll> > q;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		isi[a[i]%m].pb(i);
	}
	for(i=0;i<2*m;i++)
	{
		ll SZ=isi[i%m].size();
		while(!q.empty()&&SZ<(n/m))
		{
			isi[i%m].pb(q.front().fi);
			has+=(i-q.front().se);
			a[q.front().fi]+=(i-q.front().se);
			q.pop();
			SZ++;
		}
		ll T=isi[i%m].size()-(n/m);
		T=max(T,0LL);
		while(T--)
		{
			q.push(mp(isi[i%m].back(),i));
			isi[i%m].pop_back();
		}
	}
	cout<<has<<"\n";
	//for(i=0;i<m;i++)cout<<i<<" "<<isi[i].size()<<"\n";
	for(i=1;i<=n;i++)
		if(i<n)
			cout<<a[i]<<" ";
		else
			cout<<a[i]<<"\n";
}