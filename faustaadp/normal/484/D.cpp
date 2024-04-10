#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[1010101],p[2][1010101],d[1010101];
ll car(ll aa,ll bb)
{
	if(aa==p[bb][aa])return aa;
	else return p[bb][aa]=car(p[bb][aa],bb);
}
ll depe(ll aa)
{
	if(aa==(n+1))return 0;
	if(d[aa]==-1)
	{
		ll X=car(aa,0);
		ll Y=car(aa,1);
		d[aa]=max(d[aa],depe(X+1)+abs(a[X]-a[aa]));
		d[aa]=max(d[aa],depe(Y+1)+abs(a[Y]-a[aa]));
		X--;
		Y--;
		if(X>=aa)d[aa]=max(d[aa],depe(X+1)+abs(a[X]-a[aa]));
		if(Y>=aa)d[aa]=max(d[aa],depe(Y+1)+abs(a[Y]-a[aa]));
	}
	return d[aa];
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)p[0][i]=i;
	for(i=1;i<=n;i++)p[1][i]=i;
	for(i=1;i<n;i++)if(a[i]<=a[i+1])p[0][i]=i+1;
	for(i=1;i<n;i++)if(a[i]>=a[i+1])p[1][i]=i+1;
	memset(d,-1,sizeof(d));
	cout<<depe(1)<<"\n";

}