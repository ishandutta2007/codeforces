#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll INF=1e18;
ll n,m,k,i,a[202020],hz,U[202020],V[202020],W[202020],p[202020];
ll car(ll aa)
{
	if(aa==p[aa])return aa;
	else return p[aa]=car(p[aa]);
}
void gab(ll aa,ll bb)
{
	p[car(aa)]=car(bb);
}
ll cek(ll aa)
{
	ll ii;
	for(ii=1;ii<=n;ii++)p[ii]=ii;
	for(ii=1;ii<=m;ii++)
	{
		if(W[ii]<=aa)
		{
			gab(U[ii],V[ii]);
		}
	}
	for(ii=2;ii<=k;ii++)
		if(car(a[ii])!=car(a[1]))
			return 0;
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=k;i++)
		cin>>a[i];
	for(i=1;i<=m;i++)
		cin>>U[i]>>V[i]>>W[i];
	ll L=1,R=1000000000,C;
	while(L<=R)
	{
		C=(L+R)/2;
		if(cek(C))
		{
			hz=C;
			R=C-1;
		}
		else
			L=C+1;
	}
	for(i=1;i<=k;i++)
		if(i<k)
			cout<<hz<<" ";
		else 
			cout<<hz<<"\n";
}