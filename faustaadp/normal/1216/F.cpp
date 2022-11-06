#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,i,d1[202020],d2[202020];
char a[202020];
priority_queue<pair<ll,ll> > pq1,pq2;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=n;i>=1;i--)
	{
		ll nx=i+k;
		while((!pq1.empty())&&(pq1.top().se>nx))pq1.pop();
		while((!pq2.empty())&&(pq2.top().se>(nx+1)))pq2.pop();
		if(!pq1.empty())
			d2[i]=-pq1.top().fi;
		else
			d2[i]=1e18;
		if(a[i]=='0')
		{
			if(i==n)
				d1[i]=i;
			else
				d1[i]=min(d1[i+1],d2[i+1])+i;
		}
		else
		{
			if(nx>=n)
				d1[i]=i;
			else
			{
				//if(!pq2.empty())
					d1[i]=i-pq2.top().fi;
			}
			pq1.push(mp(-d1[i],i));
		}
		pq2.push(mp(-min(d1[i],d2[i]),i));
	}
	cout<<min(d1[1],d2[1])<<"\n";
}