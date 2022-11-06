#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[101010],b[101010],d[101010],hz,has,B[101010],z[101010];
void cek(ll aa)
{
	queue<ll> q;
	q.push(aa);
	z[aa]=0;
	B[aa]=i;
	while(!q.empty())
	{
		ll u=q.front();
		b[u]++;
		d[u]+=z[u];
		q.pop();
		if(u*2<=100000&&B[u*2]!=i)
		{
			B[u*2]=i;
			z[u*2]=z[u]+1;
			q.push(u*2);
		}
		ll nx=u/2;
		if(nx>0&&B[nx]!=i)
		{
			z[nx]=z[u]+1;
			B[nx]=i;
			q.push(nx);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)
	{
		cek(a[i]);
	}
	//cout<<b[1]<<"\n";
	//cout<<b[8]<<"\n";
	has=1e18;
	for(i=1;i<=100000;i++)
		if(b[i]==n)
		{
//			cout<<i<<"\n";
			has=min(has,d[i]);
		}
	cout<<has<<"\n";
}