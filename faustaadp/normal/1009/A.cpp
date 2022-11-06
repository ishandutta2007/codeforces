#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,b[1010],a[1010],d[1010][1010];
ll depe(ll aa,ll bb)
{
	if(aa>n||bb>m)	return 0;
	if(d[aa][bb]==-1)
	{
		d[aa][bb]=depe(aa+1,bb);
		if(a[aa]<=b[bb])
			d[aa][bb]=max(d[aa][bb],depe(aa+1,bb+1)+1);
	}
	return d[aa][bb];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=m;i++)
		cin>>b[i];
	memset(d,-1,sizeof(d));
	cout<<depe(1,1)<<"\n";
}