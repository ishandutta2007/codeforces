#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,k,i,p[202020],d[202020],ta,tb,A[202020],a[202020];
ll depe(ll aa)
{
	if(aa==0)return 0;
	if(d[aa]==-1)
	{
		d[aa]=depe(aa-1)+a[aa];
		ll ii;
		for(ii=1;ii<=aa;ii++)
		{
			if(A[ii]==0)continue;
			d[aa]=min(d[aa],depe(aa-ii)+p[aa]-p[aa-ii+A[ii]]);
		}
	}
	return d[aa];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	cin>>n>>m>>k;
	memset(d,-1,sizeof(d));
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
		p[i]=p[i-1]+a[i];
	for(i=1;i<=m;i++)
	{
		cin>>ta>>tb;
		A[ta]=max(A[ta],tb);
	}
	cout<<depe(k)<<"\n";
}